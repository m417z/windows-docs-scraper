# IMbnConnectionProfileEvents::OnProfileUpdate

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

A notification method that indicates that profile update operation has completed.

## Parameters

### `newProfile` [in]

An [IMbnConnectionProfile](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectionprofile) interface that represents the profile that has changed.

## Return value

This method must return **S_OK**.

## Remarks

**OnProfileUpdate** is called to notify a registered application of the completion of an operation initiated by a call to the [UpdateProfile](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnconnectionprofile-updateprofile) method of the [IMbnConnectionProfile](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectionprofile) interface, or the [CreateConnectionProfile](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnconnectionprofilemanager-createconnectionprofile) of the [IMbnConnectionProfileManager](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectionprofilemanager) interface.

## See also

[IMbnConnectionProfileEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectionprofileevents)