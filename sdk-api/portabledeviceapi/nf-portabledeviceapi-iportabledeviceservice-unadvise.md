# IPortableDeviceService::Unadvise

## Description

The **Unadvise** method unregisters a service event callback object.

## Parameters

### `pszCookie` [in]

The unique context ID for the application-supplied callback object. This value matches that yielded by the *ppszCookie* parameter of the [Advise](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledeviceservice-advise) method.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | A **NULL** parameter was specified. |

## See also

[IPortableDeviceService Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservice)