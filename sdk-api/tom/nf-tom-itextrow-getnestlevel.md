# ITextRow::GetNestLevel

## Description

Gets the nest level of a table.

## Parameters

### `pValue` [out, retval]

Type: **long***

The nest level.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The nest level of the table is identified by the associated [ITextRange2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange2) object. If there is only a single table, the nest level is 1. If there is no table, the nest level is 0.

## See also

[ITextRow](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrow)