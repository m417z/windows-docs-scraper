# ITextRange2::GetTable

## Description

Not implemented.

Gets the table properties in the currently selected table.

## Parameters

### `ppTable` [out, retval]

Type: **IUnknown****

The table properties.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To select the table when the insertion point is inside a table, call [ITextRange::Expand](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-expand)(tomTable).

Note: this method isn't implemented in RichEdit (see [ITextRow](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrow) for table functionality).

## See also

[ITextRange2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange2)