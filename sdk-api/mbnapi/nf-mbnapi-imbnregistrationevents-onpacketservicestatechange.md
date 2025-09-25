# IMbnRegistrationEvents::OnPacketServiceStateChange

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Notification method called by the Mobile Broadband service to indicate a change in the device packet service state.

## Parameters

### `newInterface` [in]

Pointer to an [IMbnRegistration](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnregistration) interface that represents the device whose packet service state has changed.

## Return value

This method must return **S_OK**.

## Remarks

The **OnPacketServiceStateChange** method is called by the Mobile Broadband service to signal a change in the packet service state of the device. This can occur if there is a change in the current data class, the available data class, or a packet attach network error.
An application can use the passed [IMbnRegistration](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnregistration) interface to get updated state values.

## See also

[IMbnRegistrationEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnregistrationevents)