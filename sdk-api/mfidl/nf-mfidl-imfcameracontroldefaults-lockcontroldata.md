## Description

Retrieves the data payload for the control associated with the **IMFCameraControlDefaults** instance, allowing clients to modify the control value directly.

## Parameters

### `control` [out]

Receives a pointer to the control being locked.

### `controlSize` [out]

Receives the size of the structure pointed to by *control*.

### `data` [out]

Receives a pointer to the data payload of the control.

### `dataSize` [out]

Receives the size of the buffer pointed to by *dataSize*.

## Return value

S_OK on success.

## Remarks

The *control* and *data* parameters are not type checked because custom controls can have arbitrary payload schema sizes.

You must call [UnlockControlData](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfcameracontroldefaults-unlockcontroldata) must be called before the collection containing the control is submitted to [IMFCameraConfigurationManager::SaveDefaults](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfcameraconfigurationmanager-savedefaults) method.

## See also

[UnlockControlData](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfcameracontroldefaults-unlockcontroldata)

[IMFCameraConfigurationManager::SaveDefaults](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfcameraconfigurationmanager-savedefaults)