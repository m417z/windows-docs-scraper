# IMFTimedTextFormattedText::GetSubformatting

## Description

Gets a subformat in the formatted timed-text object.

## Parameters

### `index` [in]

Type: **DWORD**

The index of the subformat in the formatted timed-text object.

### `firstChar` [out]

Type: **DWORD***

A pointer to a variable that receives the first character of the subformat.

### `charLength` [out]

Type: **DWORD***

A pointer to a variable that receives the length, in characters, of the subformat.

### `style` [out]

Type: **[IMFTimedTextStyle](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imftimedtextstyle)****

A pointer to a memory block that receives a pointer to the [IMFTimedTextStyle](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imftimedtextstyle) interface for the subformat's timed-text style. This parameter can be **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFTimedTextFormattedText](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imftimedtextformattedtext)