# ITextRow::SetRTL

## Description

Sets whether this row has right-to-left orientation.

## Parameters

### `Value` [in]

Type: **long**

A [tomBool](https://learn.microsoft.com/windows/desktop/Controls/about-text-object-model) value that can be one of the following.

| Value | Meaning |
| --- | --- |
| **tomTrue** | Right-to-left orientation. |
| **tomFalse** | Left-to-right orientation. |
| **tomToggle** | Toggles the orientation. |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextRow](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrow)

[ITextRow::GetRTL](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrow-getrtl)