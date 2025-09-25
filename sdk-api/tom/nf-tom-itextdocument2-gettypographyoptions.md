# ITextDocument2::GetTypographyOptions

## Description

Gets the typography options.

## Parameters

### `pOptions` [out, retval]

Type: **long***

A combination of the following typography options.

| Value | Meaning |
| --- | --- |
| **TO_ADVANCEDTYPOGRAPHY** | Advanced typography (special line breaking and line formatting) is turned on. |
| **TO_SIMPLELINEBREAK** | Normal line breaking and formatting is used. |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextDocument2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument2)

[ITextDocument2::SetTypographyOptions](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument2-settypographyoptions)