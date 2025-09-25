# IMbnConnection::GetVoiceCallState

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Gets the voice call state of the device.

## Parameters

### `voiceCallState` [out, retval]

A pointer to a [MBN_VOICE_CALL_STATE](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_voice_call_state) value that specifies the voice call state. If the method returns anything other than **S_OK**, the contents of this pointer are not set.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_PENDING** | The call state not available. The Mobile Broadband service is probing the device for the information. The calling application can be notified when the call state is available by registering for the [OnVoiceCallStateChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnconnectionevents-onvoicecallstatechange) method of [IMbnConnectionEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectionevents). |
| **E_MBN_PIN_REQUIRED** | A PIN is required to get the call state. |
| **E_MBN_SIM_NOT_INSERTED** | A SIM is not inserted in the device. |
| **E_MBN_BAD_SIM** | A bad SIM is inserted in the device. |

## Remarks

For the recoverable errors **E_MBN_PIN_REQUIRED**, **E_MBN_SIM_NOT_INSERTED**, and **E_MBN_BAD_SIM**, the Mobile Broadband service will query the device again for this information once the error condition is over. For example, if the device required a PIN to be entered to retrieve the voice call state, then **E_MBN_PIN_REQUIRED** is returned. After the calling application enters the PIN to unlock the device, the Mobile Broadband service will again try to get the voice call state from the device. The Mobile Broadband service will update the application with the status of a new probe by calling the [OnVoiceCallStateChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnconnectionevents-onvoicecallstatechange) method of [IMbnConnectionEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectionevents).

## See also

[IMbnConnection](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnection)