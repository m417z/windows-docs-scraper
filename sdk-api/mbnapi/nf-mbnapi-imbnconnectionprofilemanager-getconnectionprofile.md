# IMbnConnectionProfileManager::GetConnectionProfile

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Gets a specific connection profile associated with the given Mobile Broadband device.

## Parameters

### `mbnInterface` [in]

An [IMbnInterface](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterface) that represents the device for which the profile request applies. If *mbnInterface* is **NULL**, then this function will return the profile of the given name associated with any device in the system.

### `profileName` [in]

A null-terminated string that contains the name of the connection profile.

### `connectionProfile` [out, retval]

An [IMbnConnectionProfile](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectionprofile) interface that represents the desired connection profile. If this method returns anything other than **S_OK**, this is **NULL**.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_HANDLE** | The interface is invalid, most likely because the Mobile Broadband device has been removed from the system. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | A profile with the given name does not exist. |
| **HRESULT_FROM_WIN32(ERROR_NOT_READY)** | The device is not ready. Unable to obtain the subscriber ID because the device is not **MBN_READY_STATE_INITIALIZED**. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | A profile with the given name does not exist. |

## Remarks

A connection profile is associated with the subscriber ID of the device. For GSM devices the subscriber ID is the International Mobile Subscriber Identity (IMSI) of the SIM. For CDMA devices it is the Mobile Identification Number (MIN) string or the International Roaming MIN (IRM) string.

If a new profile has been created using [CreateConnectionProfile](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnconnectionprofilemanager-createconnectionprofile), then the caller must wait for the [OnConnectionProfileArrival](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnconnectionprofilemanagerevents-onconnectionprofilearrival) event to be received before calling **GetConnectionProfile** with the new profile's name; otherwise, the **GetConnectionProfile** API call may fail with **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)**.

## See also

[IMbnConnectionProfileManager](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectionprofilemanager)