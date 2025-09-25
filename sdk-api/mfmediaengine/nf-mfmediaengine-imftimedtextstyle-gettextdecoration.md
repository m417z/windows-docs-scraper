# IMFTimedTextStyle::GetTextDecoration

## Description

Gets how text is decorated for the timed-text style.

## Parameters

### `textDecoration` [out]

Type: **DWORD***

A pointer to a variable that receives a combination of [MF_TIMED_TEXT_DECORATION](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/ne-mfmediaengine-mf_timed_text_decoration)-typed values that are combined by using a bitwise OR operation. The resulting value specifies how text is decorated.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFTimedTextStyle](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imftimedtextstyle)