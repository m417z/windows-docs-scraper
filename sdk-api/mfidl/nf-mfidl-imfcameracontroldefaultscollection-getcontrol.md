## Description

Gets the control from the collection using the specified zero-based index.

## Parameters

### `index` [in]

The index of the control to retrieve.

### `configuration`

Receives a pointer to a [IMFCameraControlDefaults](https://learn.microsoft.com/windows/win32/api/mfidl/nn-mfidl-imfcameracontroldefaults) instance representing the retrieved control.

## Return value

A HRESULT value, including the following.

| Value | Description |
|-------|-------------|
| S_OK | Success. |
| MF_E_INVALIDINDEX | The index was out of the allowed range.

## Remarks

The specified index must be less than the value returned by [GetControlCount](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfcameracontroldefaultscollection-getcontrolcount).

## See also