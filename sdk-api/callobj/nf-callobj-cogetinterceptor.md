# CoGetInterceptor function

## Description

Instantiates the appropriate interceptor for the specified interface to be intercepted and returns the newly created interceptor.

## Parameters

### `iidIntercepted` [in]

A reference to the identifier of the interface for which an interceptor is to be returned.

### `punkOuter` [in]

If this parameter is **NULL**, the object is not being created as part of an aggregate. Otherwise, this parameter is a pointer to the aggregate object's [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface (the controlling **IUnknown**).

### `iid` [in]

 A reference to the identifier of the interface desired on the interceptor.

### `ppv` [out]

The address of a pointer variable that receives the interface pointer requested in *iid*. Upon successful return, ***ppv* contains the requested interceptor pointer.

## Return value

This function can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The function returned successfully. |
| **E_UNEXPECTED** | An unexpected error occurred. |

## See also

[ICallFrame](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframe)

[ICallFrameEvents](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframeevents)

[ICallInterceptor](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallinterceptor)

[ICallUnmarshal](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallunmarshal)

[ISurrogateService](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-isurrogateservice)