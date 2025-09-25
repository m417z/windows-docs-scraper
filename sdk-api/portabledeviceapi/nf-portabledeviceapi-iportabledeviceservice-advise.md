# IPortableDeviceService::Advise

## Description

The **Advise** method registers an application-defined callback object that receives service events.

## Parameters

### `dwFlags` [in]

Not used.

### `pCallback` [in]

The [IPortableDeviceEventCallback](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceeventcallback) interface specifying the callback object to register.

### `pParameters` [in]

The [IPortableDeviceValues](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicevalues) interface specifying the event-registration parameters, or **NULL** if the callback object is to receive all service events.

### `ppszCookie` [out]

The unique context ID for the callback object. This value matches that used by the [Unadvise](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledeviceservice-unadvise) method to unregister the callback object.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | A **NULL** value was specified for the *pCallback* parameter or the *ppszCookie* parameter. |

## Remarks

During cleanup, an application should unregister the callback object by calling the [Unadvise](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledeviceservice-unadvise) method, and then release the memory referenced by the *ppszCookie* parameter by calling the **CoTaskMemFree** function.

## See also

[IPortableDeviceService Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservice)