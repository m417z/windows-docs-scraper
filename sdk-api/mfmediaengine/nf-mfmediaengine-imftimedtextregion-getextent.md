# IMFTimedTextRegion::GetExtent

## Description

Gets the extent of the region.

## Parameters

### `pWidth` [out]

Type: **double***

A pointer to a variable that receives the width of the region.

### `pHeight` [out]

Type: **double***

A pointer to a variable that receives the height of the region.

### `unitType` [out]

Type: **[MF_TIMED_TEXT_UNIT_TYPE](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/ne-mfmediaengine-mf_timed_text_unit_type)***

A pointer to a variable that receives a [MF_TIMED_TEXT_UNIT_TYPE](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/ne-mfmediaengine-mf_timed_text_unit_type)-typed value that specifies the units in which the timed-text region is measured.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFTimedTextRegion](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imftimedtextregion)