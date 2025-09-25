# IMbnRegistrationEvents::OnRegisterStateChange

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Notification method called by the Mobile Broadband service to indicate a change in the device's registration state.

## Parameters

### `newInterface` [in]

Pointer to an [IMbnRegistration](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnregistration) interface that represents the applicable device.

## Return value

This method must return **S_OK**.

## Remarks

The **OnRegisterStateChange** method is called by the Mobile Broadband service to signal a change in the device registration state. It may be called if any of the following changes:

* There is a change in the registration state of the device. For example, if the device goes from its home network to a roaming network, then the registration state can change from **MBN_REGISTER_STATE_HOME** to **MBN_REGISTER_STATE_ROAMING**.
* There is a change in registered provider ID, name, or roaming text.
* There is a change in the last reported network error code for a registration operation.

An application can use the passed [IMbnRegistration](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnregistration) interface to get the updated registration state data.

## See also

[IMbnRegistrationEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnregistrationevents)