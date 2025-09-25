# IMbnConnectionProfile::Delete

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Deletes the profile from the system.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_HANDLE** | The profile is invalid and likely has been removed from the system. |
| **HRESULT_FROM_WIN32(ERROR _NOT_FOUND)** | The profile is invalid and has likely been removed from the system. |
| **HRESULT_FROM_WIN32(ERROR_SERVICE_NOT_ACTIVE)** | The Mobile Broadband service is not running on this system. |

## Remarks

This is an asynchronous operation. The Mobile Broadband service will notify the calling application by calling the [OnConnectionProfileRemoval](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnconnectionprofilemanagerevents-onconnectionprofileremoval) method of the [IMbnConnectionProfileManagerEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectionprofilemanagerevents) interface.

## See also

[IMbnConnectionProfile](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectionprofile)