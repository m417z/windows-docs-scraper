# IPortableDeviceServiceMethods::InvokeAsync

## Description

The **InvokeAsync** method asynchronously invokes a method.

## Parameters

### `Method` [in]

The method to invoke.

### `pParameters` [in]

A pointer to an [IPortableDeviceValues](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicevalues) interface that contains the parameters of the invoked method, or **NULL** to indicate that the method has no parameters.

### `pCallback` [in]

A pointer to an application-supplied [IPortableDeviceServiceMethodCallback](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservicemethodcallback) callback object that receives the method results, or **NULL** to ignore the method results.

## Return value

If the method succeeds, it returns **S_OK**. Any other **HRESULT** value indicates that the call failed.

## Remarks

When invoking multiple methods, clients can create a separate instance of the [IPortableDeviceServiceMethodCallback](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservicemethodcallback) interface for each invocation, saving a context with that instance object before passing it to the **InvokeAsync** method. This way, the method operation can be identified when the [OnComplete](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledeviceservicemethodcallback-oncomplete) method is called. Use of a unique object for each invocation also allows targeted cancellation of an operation by the [Cancel](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledeviceservicemethods-cancel) method.

#### Examples

For an example of how to use this method, see [Invoking Service Methods Asynchronously](https://learn.microsoft.com/windows/desktop/wpd_sdk/invoking-methods-asynchronously).

## See also

[IPortableDeviceServiceMethods Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservicemethods)

[Invoking Service Methods Asynchronously](https://learn.microsoft.com/windows/desktop/wpd_sdk/invoking-methods-asynchronously)