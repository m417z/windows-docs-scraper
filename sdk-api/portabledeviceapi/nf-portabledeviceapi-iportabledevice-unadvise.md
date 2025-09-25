# IPortableDevice::Unadvise

## Description

The **Unadvise** method unregisters a client from receiving callback notifications. You must call this method if you called [Advise](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevice-advise) previously.

## Parameters

### `pszCookie` [in]

Pointer to a null-terminated string that is a unique context ID. This was retrieved in the initial call to [IPortableDevice::Advise](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevice-advise).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IPortableDevice Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevice)