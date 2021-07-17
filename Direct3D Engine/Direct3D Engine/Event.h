class Event
{
public:

    virtual ~Event() {}
    virtual void operator() (GLFWwindow* _window, int _action) = 0;
};

class EventFunction : public Event
{
public:

    EventFunction(void (*_func)(GLFWwindow*, int)) : func_(_func) {}

    virtual void operator() (GLFWwindow* _window, int _action) { return (*func_)(_window, _action); }

private:

    void (*func_)(GLFWwindow*, int);
};

template <typename T>
class EventClassFunction : public Event
{
public:

    EventClassFunction(T* instance, void (T::* memberfunction)(GLFWwindow*, int)) : instance_(instance), memberfunc_(memberfunction) {}

    virtual void operator() (GLFWwindow* _window, int _action) { return (instance_->*memberfunc_)(_window, _action); }

private:

    T* instance_;
    void (T::* memberfunc_)(GLFWwindow*, int);
};
