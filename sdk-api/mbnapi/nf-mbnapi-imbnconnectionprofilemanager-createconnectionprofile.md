# IMbnConnectionProfileManager::CreateConnectionProfile

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Creates a new connection profile for the device.

## Parameters

### `xmlProfile` [in]

A null-terminated string that contains the profile data in XML format compliant with the [Mobile Broadband Profile Schema Reference](https://learn.microsoft.com/windows/desktop/mbn/schema-schema).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **HRESULT_FROM_WIN32(ERROR_ALREADY_EXISTS)** | A profile with the given name already exists. |
| **E_MBN_INVALID_PROFILE** | The profile does not conform to the Mobile Broadband profile schema. |
| **HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)** | The icon file location passed in the profile is not valid or not accessible. |
| **E_MBN_DEFAULT_PROFILE_EXIST** | The calling application specified the default profile flag in the XML data, however the default profile already exists for the Mobile Broadband device. |

## Remarks

This is a synchronous operation. If this function call is successful, then a new profile will be created and the Mobile Broadband service will call the [OnConnectionProfileArrival](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnconnectionprofilemanagerevents-onconnectionprofilearrival) method of the [IMbnConnectionProfileManagerEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectionprofilemanagerevents) interface.

If the icon file location is specified in the profile data then the Mobile Broadband service will copy the icon file from the specified location in its own store. A subsequent query on the [IMbnConnectionProfile](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectionprofile) object for the icon file location will return the file location where the Mobile Broadband service stored the icon file. Whenever a profile is deleted from the system, its icon file is also deleted from the system. The icon file should be in bmp file format file with 32x32 pixel dimensions.

## See also

[IMbnConnectionProfileManager](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectionprofilemanager)