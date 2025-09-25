# IMbnConnectionProfileManager::GetConnectionProfiles

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Gets a list of connection profiles associated with the device.

## Parameters

### `mbnInterface` [in]

An [IMbnInterface](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterface) that represents the device for which the profile request applies. If this is **NULL**, the function will return all of the profiles that are present in the system.

### `connectionProfiles` [out, retval]

An array of [IMbnConnectionProfile](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectionprofile) interfaces that represent all the available connection profiles for the device. If this method returns anything other than **S_OK**, the array pointer is **NULL**, otherwise the calling application must eventually free the allocated memory by calling [SafeArrayDestroy](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-safearraydestroy).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_HANDLE** | The interface is invalid, most likely because the Mobile Broadband device has been removed from the system. |
| **HRESULT_FROM_WIN32(ERROR_NOT_READY)** | The device is not ready. Unable to obtain the subscriber ID because the device is not **MBN_READY_STATE_INITIALIZED**. |
| **HRESULT_FROM_WIN32(ERROR_SERVICE_NOT_ACTIVE)** | The Mobile Broadband service is not running on this system. |

## Remarks

 When this operation is called for a particular device, it returns a list of profiles which have the same subscriber ID as currently reported by device. The [GetSubscriberInformation](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterface-getsubscriberinformation) method of [IMbnInterface](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterface) can be used to obtain the subscriber ID associated with the interface.

A connection profile is associated with the subscriber ID of the device. For GSM devices the subscriber ID is the International Mobile Subscriber Identity (IMSI) of the SIM. For CDMA devices it is the Mobile Identification Number (MIN) string or the International Roaming MIN (IRM) string.

## See also

[IMbnConnectionProfileManager](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectionprofilemanager)