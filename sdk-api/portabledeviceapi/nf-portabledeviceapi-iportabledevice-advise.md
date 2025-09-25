# IPortableDevice::Advise

## Description

The **Advise** method registers an application-defined callback that receives device events.

## Parameters

### `dwFlags` [in]

**DWORD** that specifies option flags.

### `pCallback` [in]

Pointer to a callback object.

### `pParameters` [in]

This parameter is ignored and should be set to **NULL**.

### `ppszCookie` [out]

A string that represents a unique context ID. This is used to unregister for callbacks when calling [Unadvise](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevice-unadvise).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The application-defined callback was successfully registered. |

## See also

[Handling Events from the Device](https://learn.microsoft.com/windows/desktop/wpd_sdk/handling-events-from-the-device)

[IPortableDevice Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevice)