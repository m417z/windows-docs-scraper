# IMbnConnectionEvents::OnVoiceCallStateChange

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Notification method that indicates a change in the voice call state of a device.

## Parameters

### `newConnection` [in]

An [IMbnConnection](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnection) interface that represents the connection for which the voice call state has changed.

## Return value

This method must return **S_OK**.

## Remarks

**OnVoiceCallStateChange** is called when voice call state is available or when there is a change in the voice call state. An application can use [IMbnConnection](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnection) to get the updated voice call state.

## See also

[IMbnConnectionEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectionevents)