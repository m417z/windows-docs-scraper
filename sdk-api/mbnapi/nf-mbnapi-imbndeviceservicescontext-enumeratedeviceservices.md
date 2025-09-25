# IMbnDeviceServicesContext::EnumerateDeviceServices

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Gets the list of supported device services by the Mobile Broadband device.

## Parameters

### `deviceServices` [out, retval]

Pointer to an array of [MBN_DEVICE_SERVICE](https://learn.microsoft.com/windows/desktop/api/mbnapi/ns-mbnapi-mbn_device_service) structures that contains the list of device service supported by the device. If **EnumerateDeviceServices** returns any value other than **S_OK**, *deviceServices* is **NULL**. Otherwise, upon completion, the calling program must free the allocated memory. Before freeing the array by calling [SafeArrayDestroy](https://learn.microsoft.com/windows/desktop/api/oleauto/nf-oleauto-safearraydestroy), the calling program must also free all the **BSTRs** in the **MBN_DEVICE_SERVICE** structure by calling [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring).

## Return value

The method can return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | The device does not support any device services. |
| **E_PENDING** | The information is not available. The Mobile Broadband service is currently probing the device to retrieve this information. |
| **Other** | An error was encountered when executing this method. |

## See also

[IMbnDeviceServicesContext](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbndeviceservicescontext)