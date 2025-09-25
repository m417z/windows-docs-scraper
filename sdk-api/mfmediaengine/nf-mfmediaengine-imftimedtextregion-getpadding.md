# IMFTimedTextRegion::GetPadding

## Description

Gets the padding that surrounds the region.

## Parameters

### `before` [out]

Type: **double***

A pointer to a variable that receives the padding before the start of the region.

### `start` [out]

Type: **double***

A pointer to a variable that receives the start of the region.

### `after` [out]

Type: **double***

A pointer to a variable that receives the padding after the end of the region.

### `end` [out]

Type: **double***

A pointer to a variable that receives the end of the region.

### `unitType` [out]

Type: **[MF_TIMED_TEXT_UNIT_TYPE](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/ne-mfmediaengine-mf_timed_text_unit_type)***

A pointer to a variable that receives a [MF_TIMED_TEXT_UNIT_TYPE](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/ne-mfmediaengine-mf_timed_text_unit_type)-typed value that specifies the units in which the timed-text region is measured.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFTimedTextRegion](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imftimedtextregion)