# IMbnRegistrationEvents::OnRegisterModeAvailable

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Notification method called by the Mobile Broadband service to indicate that registration mode information is available.

## Parameters

### `newInterface` [in]

Pointer to an [IMbnRegistration](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnregistration) interface that represents the applicable device.

## Return value

This method must return **S_OK**.

## Remarks

The **OnRegisterModeAvailable** method is called by the Mobile Broadband service to signal that the registration mode information for a device is available. An application can call the [GetRegisterMode](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnregistration-getregistermode) method of the passed [IMbnRegistration](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnregistration) get the current registration mode of the device.

## See also

[IMbnRegistrationEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnregistrationevents)