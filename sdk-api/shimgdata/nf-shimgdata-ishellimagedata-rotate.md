# IShellImageData::Rotate

## Description

Rotates an image in increments of 90 degrees.

## Parameters

### `dwAngle` [in]

Type: **DWORD**

The angle of rotation. Only angles of 0, 90, 180, and 270 are recognized.

## Return value

Type: **HRESULT**

Returns S_OK if successful or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **E_FAIL** | The image has not been decoded or the decoding process failed. This value is also returned when certain internal calls to GDI+ methods fail. |
| **E_NOTVALIDFORANIMATEDIMAGE** | The image is an animated image and cannot be rotated. |
| **E_INVALIDARG** | The *dwAngle* parameter is a value other than 0, 90, 180, or 270. |
| **S_FALSE** | The *dwAngle* parameter is 0. |
| **E_OUTOFMEMORY** | Not enough resources are available for the method to create an internal working copy of the image. |