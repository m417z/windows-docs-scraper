# IMFTimedTextRegion::GetPosition

## Description

Gets the position of the region.

## Parameters

### `pX` [out]

Type: **double***

A pointer to a variable that receives the X-coordinate of the position.

### `pY` [out]

Type: **double***

A pointer to a variable that receives the Y-coordinate of the position.

### `unitType` [out]

Type: **[MF_TIMED_TEXT_UNIT_TYPE](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/ne-mfmediaengine-mf_timed_text_unit_type)***

A pointer to a variable that receives a [MF_TIMED_TEXT_UNIT_TYPE](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/ne-mfmediaengine-mf_timed_text_unit_type)-typed value that specifies the units in which the timed-text region is measured.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFTimedTextRegion](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imftimedtextregion)