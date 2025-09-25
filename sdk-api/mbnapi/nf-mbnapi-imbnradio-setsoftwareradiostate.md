# IMbnRadio::SetSoftwareRadioState

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Sets the software radio state of a Mobile Broadband device.

## Parameters

### `radioState` [in]

A [MBN_RADIO](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_radio) value that specifies the new software radio state.

### `requestID` [out]

A pointer to a request ID assigned by the Mobile Broadband service to identify this request.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_HANDLE** | The interface is invalid. Most likely,the Mobile Broadband device has been removed from the system. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | The interface is invalid. Most likely the Mobile Broadband device has been removed from the system. |
| **HRESULT_FROM_WIN32(ERROR_SERVICE_NOT_ACTIVE)** | The Mobile Broadband service is not running on this system. |

## Remarks

**SetSoftwareRadioState** changes the software radio state of the device. This is an asynchronous operation and it will return immediately. On completion, the Mobile Broadband service will call the [OnSetSoftwareRadioStateComplete](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnradioevents-onsetsoftwareradiostatecomplete) method of the [IMbnRadioEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnradioevents) interface.

Disabling the radio for a Mobile Broadband device will result in deactivation of any active connection, network packet detach, and network deregistration. If the radio off operation results in a change in the connection state, packet attach state, or network registration state, then the application will receive a notification of the changes.

When both software and hardware radio are enabled for a Mobile Broadband device, it will automatically try to register to the network. Also, some devices may also try to a perform packet attach to the network. Whenever the state changes, the calling application will receive event notifications for network registration and packet attach state changes.

A device's radio state can change without a change request from the application. For instance, if a user turns on the system's hardware radio switch. The Mobile Broadband service will notify the application about a change in radio state by calling the [OnRadioStateChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnradioevents-onradiostatechange) method of the [IMbnRadioEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnradioevents) interface.

## See also

[IMbnRadio](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnradio)