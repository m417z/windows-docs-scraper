# ISurrogateService::Init

## Description

Initializes the process server.

## Parameters

### `rguidProcessID` [in]

The process ID of the server application.

### `pProcessLock` [in]

A pointer to an instance of the [IProcessLock](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iprocesslock) interface.

### `pfApplicationAware` [out]

Indicates whether the application is aware of the initialization.

## Return value

If the method succeeds, the return value is S_OK. Otherwise, it is E_UNEXPECTED.

## See also

[CoGetInterceptor](https://learn.microsoft.com/windows/desktop/api/callobj/nf-callobj-cogetinterceptor)

[ICallFrame](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframe)

[ICallFrameEvents](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframeevents)

[ICallInterceptor](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallinterceptor)

[ICallUnmarshal](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallunmarshal)

[ISurrogateService](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-isurrogateservice)