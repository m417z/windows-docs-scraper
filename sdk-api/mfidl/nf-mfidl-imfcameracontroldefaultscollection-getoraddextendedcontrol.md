## Description

Adds a new extended camera control to the camera control collection.

## Parameters

### `configType` [in]

A value from the [MF_CAMERA_CONTROL_CONFIGURATION_TYPE](https://learn.microsoft.com/windows/win32/api/mfidl/ne-mfidl-mf_camera_control_configuration_type) specifying whether the control value must be set before streaming begins or after streaming starts.

### `constrolId` [in]

The ID of the control to be added to the collection. This value must be an ID in the [KSPROPERTYSETID_ExtendedCameraControl](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropertysetid-extendedcameracontrol) property set.

### `streamId` [in]

The ID of the stream associated with the control. This paramater is only used for pin-level controls. Otherwise, this value is ignored.

### `dataSize` [in]

The size of the data payload for the control, in bytes.

### `defaults` [out]

Receives a pointer to a [IMFCameraControlDefaults](https://learn.microsoft.com/windows/win32/api/mfidl/nn-mfidl-imfcameracontroldefaults) instance representing the added control.

## Return value

An HRESULT, including the following:

| Value | Description |
|------------|-----------|
| S_OK | Success. |
| MF_E_INVALIDREQUEST | The specified control ID is not in the KSPROPERTYSETID_ExtendedCameraControl property set. |

## Remarks

The data payload size may vary for different controls. The *dataSize* value must be valid for the control payload schema so the control can reserve the buffer required.

## See also