# ITextRow::IsEqual

## Description

Compares two table rows to determine if they have the same properties.

## Parameters

### `pRow` [in]

Type: **[ITextRow](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrow)***

The row to compare to.

### `pB` [out, retval]

Type: **long***

 The comparison result. The value is set to **tomTrue** if equal, and **tomFalse** if not. The value can be **NULL**.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextRow](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrow)