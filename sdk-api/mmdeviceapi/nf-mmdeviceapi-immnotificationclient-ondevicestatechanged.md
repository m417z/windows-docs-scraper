# IMMNotificationClient::OnDeviceStateChanged

## Description

The **OnDeviceStateChanged** method indicates that the state of an audio endpoint device has changed.

## Parameters

### `pwstrDeviceId` [in]

Pointer to the [endpoint ID string](https://learn.microsoft.com/windows/desktop/CoreAudio/endpoint-id-strings) that identifies the audio endpoint device. This parameter points to a null-terminated, wide-character string containing the endpoint ID. The string remains valid for the duration of the call.

### `dwNewState` [in]

Specifies the new state of the endpoint device. The value of this parameter is one of the following [DEVICE_STATE_XXX](https://learn.microsoft.com/windows/desktop/CoreAudio/device-state-xxx-constants) constants:

DEVICE_STATE_ACTIVE

DEVICE_STATE_DISABLED

DEVICE_STATE_NOTPRESENT

DEVICE_STATE_UNPLUGGED

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

For a code example that implements the **OnDeviceStateChanged** method, see [Device Events](https://learn.microsoft.com/windows/desktop/CoreAudio/device-events).

## See also

[IMMNotificationClient Interface](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immnotificationclient)