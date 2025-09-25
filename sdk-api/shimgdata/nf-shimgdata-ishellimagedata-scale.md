# IShellImageData::Scale

## Description

Adjusts the size of an image.

## Parameters

### `cx` [in]

Type: **ULONG**

The horizontal (x) dimension. If this value is 0, the x dimension is set to a scaled value based on the point specified in *cy*.

### `cy` [in]

Type: **ULONG**

The vertical (y) dimension. If this value is 0, the y dimension is set to a scaled value based on the point specified in *cx*.

### `hints` [in]

Type: **[InterpolationMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-interpolationmode)**

A member of the [InterpolationMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-interpolationmode) enumeration, specifying the algorithm that is used when the image is scaled.

## Return value

Type: **HRESULT**

Returns **S_OK** if successful or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **E_FAIL** | The image was not previously decoded or the call to [IShellImageData::Decode](https://learn.microsoft.com/windows/desktop/api/shimgdata/nf-shimgdata-ishellimagedata-decode) failed. Other internal calls also can cause this error to be returned. |
| **E_NOTVALIDFORANIMATEDIMAGE** | The image is an animated image and cannot be scaled using this method. |
| **E_OUTOFMEMORY** | The internal object cannot be instantiated. |
| **E_ABORT** | The process was stopped by the calling application through a registered instance of [IShellImageDataAbort](https://learn.microsoft.com/windows/desktop/api/shimgdata/nn-shimgdata-ishellimagedataabort). |