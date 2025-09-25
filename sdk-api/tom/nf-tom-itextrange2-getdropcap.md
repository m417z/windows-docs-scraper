# ITextRange2::GetDropCap

## Description

Not implemented.

Gets the drop-cap parameters of the paragraph that contains this range.

## Parameters

### `pcLine` [out]

Type: **long***

The count of lines for the drop cap. A value of 0 means no drop cap.

### `pPosition` [out]

Type: **long***

The position of the drop cap. The position can be one of the following:

* tomDropMargin
* tomDropNone
* tomDropNormal

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextRange2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange2)

[ITextRange2::SetDropCap](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange2-setdropcap)