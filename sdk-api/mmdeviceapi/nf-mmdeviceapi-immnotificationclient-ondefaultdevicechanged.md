# IMMNotificationClient::OnDefaultDeviceChanged

## Description

The **OnDefaultDeviceChanged** method notifies the client that the default audio endpoint device for a particular [device role](https://learn.microsoft.com/windows/desktop/CoreAudio/device-roles) has changed.

## Parameters

### `flow` [in]

The data-flow direction of the endpoint device. This parameter is set to one of the following [EDataFlow](https://learn.microsoft.com/windows/win32/api/mmdeviceapi/ne-mmdeviceapi-edataflow) enumeration values:

eRender

eCapture

The data-flow direction for a rendering device is eRender. The data-flow direction for a capture device is eCapture.

### `role` [in]

The [device role](https://learn.microsoft.com/windows/win32/api/mmdeviceapi/ne-mmdeviceapi-erole) of the audio endpoint device. This parameter is set to one of the following [ERole](https://learn.microsoft.com/windows/win32/api/mmdeviceapi/ne-mmdeviceapi-erole) enumeration values:

eConsole

eMultimedia

eCommunications

### `pwstrDefaultDeviceId` [in]

Pointer to the [endpoint ID string](https://learn.microsoft.com/windows/desktop/CoreAudio/endpoint-id-strings) that identifies the audio endpoint device. This parameter points to a null-terminated, wide-character string containing the endpoint ID. The string remains valid for the duration of the call. If the user has removed or disabled the default device for a particular role, and no other device is available to assume that role, then *pwstrDefaultDevice* is **NULL**.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

The three input parameters specify the data-flow direction, device role, and endpoint ID string of the new default audio endpoint device.

In Windows Vista, the MMDevice API supports device roles but the system-supplied user interface programs do not. The user interface in Windows Vista enables the user to select a default audio device for rendering and a default audio device for capture. When the user changes the default rendering or capture device, the system assigns all three device roles (eConsole, eMultimedia, and eCommunications) to the new device. Thus, when the user changes the default rendering or capture device, the system calls the client's **OnDefaultDeviceChanged** method three times—once for each of the three device roles.

In a future version of Windows, the user interface might enable the user to assign individual roles to different devices. In that case, if the user changes the assignment of only one or two device roles to a new rendering or capture device, the system will call the client's **OnDefaultDeviceChanged** method only once or twice (that is, one call per changed role). Depending on how the **OnDefaultDeviceChanged** method responds to role changes, the behavior of an audio application developed to run in Windows Vista might change when run in a future version of Windows. For more information, see [Device Roles in Windows Vista](https://learn.microsoft.com/windows/desktop/CoreAudio/device-roles-in-windows-vista).

For a code example that implements the **OnDefaultDeviceChanged** method, see [Device Events](https://learn.microsoft.com/windows/desktop/CoreAudio/device-events).

## See also

[IMMNotificationClient Interface](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immnotificationclient)