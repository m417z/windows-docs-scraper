# ISurrogateService::ProcessShutdown

## Description

Shuts down the process.

## Parameters

### `shutdownType` [in]

The shutdown type, as described in Remarks.

## Return value

If the method succeeds, the return value is S_OK. Otherwise, it is E_UNEXPECTED.

## Remarks

The shutdown type is defined by the following enum.

``` syntax
typedef enum tagShutdownType {
    IdleShutdown,
    ForcedShutdown
} ShutdownType;

```

## See also

[CoGetInterceptor](https://learn.microsoft.com/windows/desktop/api/callobj/nf-callobj-cogetinterceptor)

[ICallFrame](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframe)

[ICallFrameEvents](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframeevents)

[ICallInterceptor](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallinterceptor)

[ICallUnmarshal](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallunmarshal)

[ISurrogateService](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-isurrogateservice)