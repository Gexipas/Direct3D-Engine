cbuffer ConstantBuffer : register(b0)
{
	float4x4 view;
	float4x4 projection;
	float4x4 object;
}

struct PSInput {
	float4 position : SV_POSITION;
	float4 color : COLOR;
	float2 uv : UV;
};

PSInput VSMain(float4 position : POSITION, float4 color : COLOR, float2 uv : UV)
{
	float4 pos = position;
	pos = mul(object, pos);
	pos = mul(view, pos);
	pos = mul(projection, pos);

	PSInput result;
	result.position = pos;
	result.color = color;
	result.uv = uv;

	return result;
}

Texture2D<float4> imageTexture	: register(t0);
SamplerState imageSampler		: register(s0);

float4 PSMain(PSInput input) : SV_TARGET{
	return imageTexture.Sample(imageSampler, input.uv);
}