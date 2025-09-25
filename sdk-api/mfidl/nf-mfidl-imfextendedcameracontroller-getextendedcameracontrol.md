## Description

Gets an instance of [IMFExtendedCameraControl](https://learn.microsoft.com/windows/win32/api/mfidl/nn-mfidl-imfextendedcameracontrol), which allows an app to get the current capture device's extended property controls.

## Parameters

### `dwStreamIndex`

A **DWORD** indicating stream index to use for this property. Specify [MF_CAPTURE_ENGINE_MEDIASOURCE](https://learn.microsoft.com/windows/win32/medfound/mf-capture-engine-mediasource-config) to indicate that the extended property is a filter-level property.

### `ulPropertyId`

The ID indicating the index for identifying the property within [KSPROPERTYSETID_ExtendedCameraControl](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropertysetid-extendedcameracontrol).

### `ppControl`

Receives a pointer to the **IMFExtendedCameraControl** instance that represents the requested control.

## Return value

Returns S_OK on success.

## Remarks

## See also