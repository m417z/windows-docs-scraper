## Description

Adds a new camera control to the camera control collection.

## Parameters

### `configType`

A value from the [MF_CAMERA_CONTROL_CONFIGURATION_TYPE](https://learn.microsoft.com/windows/win32/api/mfidl/ne-mfidl-mf_camera_control_configuration_type) specifying whether the control value must be set before streaming begins or after streaming starts.

### `controlSet`

A GUID specifying the control set to which the control belongs. If the **controlSet** is **KSPROPERTYSETID_ExtendedCameraControl** please use the dedicated [GetOrAddExtendedControl](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfcameracontroldefaultscollection-getoraddextendedcontrol) function.

### `constrolId`

The ID of the control to be added to the collection.

### `controlSize`

The size of the control, in bytes. This value must be greater than or equal to the size of [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure).

### `dataSize`

The size of the data payload for the control, in bytes.

### `defaults`

Receives a pointer to a [IMFCameraControlDefaults](https://learn.microsoft.com/windows/win32/api/mfidl/nn-mfidl-imfcameracontroldefaults) instance representing the added control.

## Return value

An HRESULT, including the following:

| Value | Description |
|------------|-----------|
| S_OK | Success. |

## Remarks

For custom controls, *controlSet* and *controlId* are based on the custom control DDI published by the camera driver vendor. Similarly, the *controlSize* and *dataSize* are based on the DDI published by the vendor.

## See also