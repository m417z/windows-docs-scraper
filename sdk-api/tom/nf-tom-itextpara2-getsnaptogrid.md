# ITextPara2::GetSnapToGrid

## Description

Gets whether paragraph lines snap to a vertical grid that could be defined for the whole document.

## Parameters

### `pValue` [out, retval]

Type: **long***

A [tomBool](https://learn.microsoft.com/windows/desktop/Controls/about-text-object-model) value that can be one of the following.

| Value | Meaning |
| --- | --- |
| **tomTrue** | Paragraph lines snap to a vertical grid. |
| **tomFalse** | Paragraph lines do not snap to a grid. |
| **tomUndefined** | The SnapToGrid property is undefined. |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextPara2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara2)

[ITextPara2::SetSnapToGrid](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara2-setsnaptogrid)