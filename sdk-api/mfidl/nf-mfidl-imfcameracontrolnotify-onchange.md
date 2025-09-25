## Description

Raised when a camera control value is changed.

## Parameters

### `controlSet`

A GUID specifying the camera control set to which the changed control belongs.

### `id`

The ID of the changed control within the control set.

## Remarks

The control for which the **OnChange** event is invoked is specified by calling [IMFCameraControlMonitor::AddControlSubscription](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfcameracontrolmonitor-addcontrolsubscription). The explicitly supported controls include the properties under [PROPSETID_VIDCAP_VIDEOPROCAMP](https://learn.microsoft.com/windows-hardware/drivers/stream/propsetid-vidcap-videoprocamp) and [PROPSETID_VIDCAP_CAMERACONTROL](https://learn.microsoft.com/windows-hardware/drivers/stream/propsetid-vidcap-videoprocamp), and [KSPROPERTYSETID_ExtendedCameraControl](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropertysetid-extendedcameracontrol). If **AddControlSubscription** is called with KSPROPERTYSETID_ANYCAMERACONTROL as the *controlSet* parameter, then the created subscription will provoke callbacks for any control change, even those outside of the previously listed property sets. If a changed control is outside of those sets, then the **OnChange** callback will have the value KSPROPERTYSETID_ANYCAMERACONTROL as its *controlSet* parameter, but for the explicitly supported property sets, the *controlSet* GUID will still return the supported property set GUID, not KSPROPERTYSETID_ANYCAMERACONTROL. The returned *id* parameter in all cases will be the control ID of the altered control.

To see a code example that implements this method, see [IMFCameraControlNotify](https://learn.microsoft.com/windows/win32/api/mfidl/nn-mfidl-imfcameracontrolnotify).

## See also