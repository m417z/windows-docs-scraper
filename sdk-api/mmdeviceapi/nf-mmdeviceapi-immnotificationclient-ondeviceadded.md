# IMMNotificationClient::OnDeviceAdded

## Description

The **OnDeviceAdded** method indicates that a new audio endpoint device has been added.

## Parameters

### `pwstrDeviceId` [in]

Pointer to the [endpoint ID string](https://learn.microsoft.com/windows/desktop/CoreAudio/endpoint-id-strings) that identifies the audio endpoint device. This parameter points to a null-terminated, wide-character string containing the endpoint ID. The string remains valid for the duration of the call.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

For a code example that implements the **OnDeviceAdded** method, see [Device Events](https://learn.microsoft.com/windows/desktop/CoreAudio/device-events).

## See also

[IMMNotificationClient Interface](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immnotificationclient)