# IPortableDeviceServiceMethods::Invoke

## Description

The **Invoke** method synchronously invokes a method.

## Parameters

### `Method` [in]

The method to invoke.

### `pParameters` [in]

A pointer to an [IPortableDeviceValues](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicevalues) interface that contains the parameters of the invoked method, or **NULL** to indicate that the method has no parameters.

### `ppResults` [in, out]

The address of a pointer to an [IPortableDeviceValues](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicevalues) interface that receives the method results, or **NULL** to ignore the method results.

## Return value

If the method succeeds, it returns **S_OK**. Any other **HRESULT** value indicates that the call failed.

## Remarks

The method invocation is synchronous and will not return until the method has completed. For long-running methods, your application should call the [InvokeAsync](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledeviceservicemethods-invokeasync) method instead.

#### Examples

For an example of how to use this method, see [Invoking Service Methods](https://learn.microsoft.com/windows/desktop/wpd_sdk/invoking-methods-synchronously)

## See also

[IPortableDeviceServiceMethods Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservicemethods)

[Invoking Service Methods](https://learn.microsoft.com/windows/desktop/wpd_sdk/invoking-methods-synchronously)