# IMFTimedTextStyle::GetTextOutline

## Description

Gets the text outline for the timed-text style.

## Parameters

### `color` [out]

Type: **[MFARGB](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfargb)***

A pointer to a variable that receives a [MFARGB](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfargb) structure that describes the color.

### `thickness` [out]

Type: **double***

A pointer to a variable that receives the thickness.

### `blurRadius` [out]

Type: **double***

A pointer to a variable that receives the blur radius.

### `unitType` [out]

Type: **[MF_TIMED_TEXT_UNIT_TYPE](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/ne-mfmediaengine-mf_timed_text_unit_type)***

A pointer to a variable that receives a [MF_TIMED_TEXT_UNIT_TYPE](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/ne-mfmediaengine-mf_timed_text_unit_type)-typed value that specifies the units in which the timed-text is measured.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFTimedTextStyle](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imftimedtextstyle)