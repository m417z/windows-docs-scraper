# IMbnConnectionProfile::UpdateProfile

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Updates the contents of the profile.

## Parameters

### `strProfile` [in]

A string that contains the profile data in XML format compliant with the [Mobile Broadband Profile Schema Reference](https://learn.microsoft.com/windows/desktop/mbn/schema-schema).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_HANDLE** | The profile is invalid and likely has been removed from the system. |
| **HRESULT_FROM_WIN32(ERROR _NOT_FOUND)** | The profile is invalid and has likely been removed from the system. |
| **HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)** | The profile data specifies an icon file that cannot be found at the indicated location. |
| **HRESULT_FROM_WIN32(ERROR_SERVICE_NOT_ACTIVE)** | The Mobile Broadband service is not running on this system. |

## Remarks

The data provided by this method complies with the [Mobile Broadband Profile Schema Reference](https://learn.microsoft.com/windows/desktop/mbn/schema-schema).

This method should be called when the device for the profile is present in the system.

This is a synchronous operation. If successful, the Mobile Broadband service will notify the calling application by calling the [OnProfileUpdate](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnconnectionprofileevents-onprofileupdate) method of the [IMbnConnectionProfileEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectionprofileevents) interface.

## See also

[IMbnConnectionProfile](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectionprofile)