# IShellImageData::Draw

## Description

Draws a decoded image.

## Parameters

### `hdc` [in]

Type: **HDC**

The handle of the image.

### `prcDest` [in]

Type: **LPRECT**

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect), measured in pixels, that specifies the bounds of the rendered image. The portion of the image specified by *prcSrc* is scaled to fill the rectangle specified by *prcDest*.

### `prcSrc` [in]

Type: **LPRECT**

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) that specifies the portion of the image to be drawn.

## Return value

Type: **HRESULT**

Returns S_OK if successful or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **E_FAIL** | The image was not previously decoded, the call to [IShellImageData::Decode](https://learn.microsoft.com/windows/desktop/api/shimgdata/nf-shimgdata-ishellimagedata-decode) failed, or *hdc* is **NULL**. Other internal calls also can cause this error to be returned. |
| **E_INVALIDARG** | The *prcDest* parameter is **NULL**. |
| **E_ABORT** | The process was terminated by the calling application through a registered instance of [IShellImageDataAbort](https://learn.microsoft.com/windows/desktop/api/shimgdata/nn-shimgdata-ishellimagedataabort). |

## Remarks

If *prcSrc* is **NULL**, nothing is drawn and the method returns S_OK.