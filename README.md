# experiments
This repo contains different source code. Not everything is complete, not everything is working.

## keylogger
To setup kbdflt on your system:

On Win32 environment edit the reg key:

`HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Windows`
or  
`HKEY_LOCAL_MACHINE\SOFTWARE\WOW6432Node\Microsoft\Windows NT\CurrentVersion\Windows`
on win64

* AppInit_DLLs (REG_SZ) => put full path of kbdflt.dll;
* LoadAppInit_DLLs (REG_DWORD) => 0x00000001
* RequireSignedAppInit_DLLs (REG_DWORD) => 0x00000000

Reminder: only data from "putty.exe" are stored inside %APPDATA%\pid_putty_random.txt

## Middleware Pattern

From `ExpressJS`

* Middleware functions are functions that have access to the request object ( req ), the response object ( res ), and the next function in the application's request-response cycle. The next function is a function in the Express router which, when invoked, executes the middleware succeeding the current middleware *

This is an implementation of this pattern at compile time, without use of STL functions, using only C++ variadic template.
The scope is purely for fun, because in all middleware context is known at runtime the sequence of functions.
Evidently, this is not the context of filter processing, but the intention is to simplify complex functions which calls in sequence other functions to process data and generate responses.
In data exchange with a remote webserver, usually a REQUEST (an API call) require differents operation before to be sent to the web-server, like encapsulation, encoding. Many of these procedures are introduced from time to time during the development.
In this way, from the same line code, it's possible to have an eye on all procedures involved.

## Use case
```cpp
middleware_function<handler1, handler2, handler3, handler4, handler5> handlers;

handlers(parameters);

struct handler1
{
    template<typename Fn>
    bool operator()(parameters, Fn next)
    {
        bool r = true;
        // do whatever...
        log("handler 1 is called...");
        // manipulate parameters
        r = next(parameters);
        // evaluate response

        return r;
    }
}
```

## How define a handler
Each handler must match the same signature of first call to middleware_parameters, plus a functor as latest argument which represents the next handler in the chain.
The latest element called by `middleware_function` is an internal function which return true.

## Example
```cpp
std::string response;
std::string request = "Hello server";

struct RR {
    const char *endpoint_;

    RR(const char *endpoint)
        : endpoint_(endpoint)
    {

    }

    std::string request;
    std::string response;
    ~RR() {}

} request("http://192.168.0.1/API/echo");

request.request = "Hi!";
middleware_function<JSONHandler, base64Handler, authHandler, httpHandler> http;
if (http(request)) {
    std::cout << "Server reply " << request.response << std::endl;
}
```

According to this example, we can involve the following elements in the request:
- JSONHandler: Take a parameter and put into an object
- base64Handler: Encode the message in base64
- authHandler: Eventually setup extra information for the authentication
- httpHandler: Will send the request, and take the response
- authHandler: Validate the response from the server
- base64Handler: Decode the message from base64
- JSONHandler: extract the response from a JSON message and put back into reponse

## How doesn't work :(
The previous approach require an object T for each step.  
Let's imagine this different approach:
```cpp
template<typename Fn, typename... Args>
bool handler1(int &i, Fn next, Args... args)
{
   std::cout << "In handler1 i equals to " << i << std::endl;
   return next(i+1, args...);
}

template<typename Fn, typename.... Args>
bool caller(??, Fn next, Args... args)
{
   std::cout << "Calling a sequence of functions... " << std::endl;
   return next(??, args...);
}
```

Now I'm stuck on this problem.. how define a <caller> template function which needs two set of variadic template parameters with a compiler which cannot identify where the first set end, what is the "next" and eventually the nexts...
In case I'll figure out there will be an update.

## thread_fork()

This project is an excercise of "thread_fork" implementation;
fork() is not supported on Win32;

thread_fork() is an experiment of avoiding to start a child thread;

Example:

main thread:
int *buffer = malloc(sizeof(int) * 1024 * 1024);    *// 1millions of integer*

if (thread_fork() != 0) {
	>[ child thread branch ]
	>  // manipulate buffer....
	>  free(buffer);	// the child thread will deallocate buffer
	>   return;
}

.. other action on main thread..

## spidump
SPI dump
