# IPortableDeviceServiceMethods::Cancel

## Description

The **Cancel** method cancels a pending method invocation.

## Parameters

### `pCallback` [in]

A pointer to the callback object whose method invocation is to be canceled, or **NULL** to cancel all pending method invocations.

## Return value

If the method succeeds, it returns **S_OK**. Any other **HRESULT** value indicates that the call failed.

## Remarks

A callback object identifies a method invocation. If the same callback object is reused for multiple calls to the [InvokeAsync](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledeviceservicemethods-invokeasync) method, all method invocations arising from these calls will be cancelled.

To enable targeted cancellation of a specific method invocation, pass a unique instance of the [IPortableDeviceServiceMethodCallback](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservicemethodcallback) interface to the [InvokeAsync](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledeviceservicemethods-invokeasync) method.

## See also

[IPortableDeviceServiceMethods Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservicemethods)