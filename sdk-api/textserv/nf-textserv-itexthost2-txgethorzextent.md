# ITextHost2::TxGetHorzExtent

## Description

Gets the horizontal scroll extent of the text host window.

## Parameters

### `plHorzExtent`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The horizontal scroll extent.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A rich edit control doesn't use the return value; instead, they get the scroll width from the widest line.

## See also

[ITextHost2](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost2)