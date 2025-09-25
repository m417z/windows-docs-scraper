# IPortableDeviceServiceMethodCallback::OnComplete

## Description

The **OnComplete** method indicates that a callback method has completed execution.

## Parameters

### `hrStatus` [in]

The overall status of the method.

### `pResults` [in]

An [IPortableDeviceValues](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicevalues) interface that contains the method-execution results. This is empty if the method returns no results.

## Return value

If the method succeeds, it returns **S_OK**. Any other **HRESULT** value indicates that the call failed.

## See also

[IPortableDeviceServiceMethodCallback Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservicemethodcallback)