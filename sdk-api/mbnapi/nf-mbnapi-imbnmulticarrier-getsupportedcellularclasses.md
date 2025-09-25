# IMbnMultiCarrier::GetSupportedCellularClasses

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Gets the list of supported cellular classes for a multi-carrier device.

## Parameters

### `cellularClasses` [out, retval]

Pointer to an array of [MBN_CELLULAR_CLASS](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_cellular_class) enumerations that contain the list of supported cellular classes. If this method returns any value other than **S_OK**, *cellularClass* is **NULL**. When **GetSupportedCellularClasses** returns **S_OK**, the calling application must free the allocated memory by calling [SafeArrayDestroy](https://learn.microsoft.com/windows/desktop/api/oleauto/nf-oleauto-safearraydestroy).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **HRESULT_FROM_WIN32(ERROR_SERVICE_NOT_ACTIVE)** | The Mobile Broadband service is not running on this system. |
| **E_HANDLE** | Invalid interface. The Mobile Broadband device has probably been removed from the system. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | Invalid interface. Most likely the Mobile Broadband device has been removed from the system. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | The operation is not supported by the device. This may be returned by devices which do not support multi-carrier. |

## See also

[IMbnMultiCarrier](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnmulticarrier)