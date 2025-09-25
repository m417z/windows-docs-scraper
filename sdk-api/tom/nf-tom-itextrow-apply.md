# ITextRow::Apply

## Description

Applies the formatting attributes of this text row object to the specified rows in the associated [ITextRange2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange2).

## Parameters

### `cRow` [in]

Type: **long**

The number of rows to apply this text row object to.

### `Flags` [in]

Type: **long**

A flag that controls how the formatting attributes are applied. It can be one of the following values.

| Value | Meaning |
| --- | --- |
| **tomCellStructureChangeOnly** | Apply formatting attributes only to cell widths or the cell count (enables you to change column widths or insert/delete columns without changing other properties, such as cell borders). |
| **tomRowApplyDefault** | Apply formatting attributes to the full application, not just cell widths and count. |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextRow](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrow)