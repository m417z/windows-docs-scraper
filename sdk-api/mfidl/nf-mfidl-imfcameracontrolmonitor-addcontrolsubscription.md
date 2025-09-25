## Description

Adds a camera control to the list of controls for which [IMFCameraControlNotify::OnChange](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfcameracontrolnotify-onchange) notifications will be raised.

## Parameters

### `controlSet`

The GUID for the camera control set to which the added control belongs.

### `id`

The ID of the control within the control set.

## Return value

An HRESULT including the following:

| Value | Description |
|-------|-------------|
| S_OK | Success |
| MF_E_INVALIDREQUEST | The camera control monitor is in the running or shutdown state. |
| MF_E_INVALIDARG | An invalid value was supplied for *controlSet*. See Remarks for more information. |

## Remarks

Attempting to add or remove subscriptions after calling [Start](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfcameracontrolmonitor-start) but before calling [Stop](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfcameracontrolmonitor-stop), or after calling [Shutdown](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfcameracontrolmonitor-shutdown), will result in an error.

The explicitly supported controls include the properties under [PROPSETID_VIDCAP_VIDEOPROCAMP](https://learn.microsoft.com/windows-hardware/drivers/stream/propsetid-vidcap-videoprocamp) and [PROPSETID_VIDCAP_CAMERACONTROL](https://learn.microsoft.com/windows-hardware/drivers/stream/propsetid-vidcap-videoprocamp), and [KSPROPERTYSETID_ExtendedCameraControl](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropertysetid-extendedcameracontrol). If **AddControlSubscription** is called with KSPROPERTYSETID_ANYCAMERACONTROL as the *controlSet* parameter, then the created subscription will provoke callbacks for any control change, even those outside of the previously listed property sets.

Specifying a value other than KSPROPERTYSETID_ANYCAMERACONTROL, PROPSETID_VIDCAP_VIDEOPROCAMP,
PROPSETID_VIDCAP_CAMERACONTROL or KSPROPERTYSETID_ExtendedCameraControl will result in an error.

To see a code example that implements this method, see [IMFCameraControlNotify](https://learn.microsoft.com/windows/win32/api/mfidl/nn-mfidl-imfcameracontrolnotify).

## See also