# ISurrogateService::ApplicationLaunch

## Description

Launches the application.

## Parameters

### `rguidApplID` [in]

The application identifier.

### `appType` [in]

The application type, as described in Remarks.

## Return value

If the method succeeds, the return value is S_OK. Otherwise, it is E_UNEXPECTED.

## Remarks

The application type is defined by the following enum.

``` syntax
typedef enum tagApplicationType {
    ServerApplication,
    LibraryApplication
} ApplicationType;

```

## See also

[CoGetInterceptor](https://learn.microsoft.com/windows/desktop/api/callobj/nf-callobj-cogetinterceptor)

[ICallFrame](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframe)

[ICallFrameEvents](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframeevents)

[ICallInterceptor](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallinterceptor)

[ICallUnmarshal](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallunmarshal)

[ISurrogateService](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-isurrogateservice)