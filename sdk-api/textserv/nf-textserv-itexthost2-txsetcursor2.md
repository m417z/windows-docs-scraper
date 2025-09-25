# ITextHost2::TxSetCursor2

## Description

Sets the shape of the cursor in the text host window.

## Parameters

### `hcur`

Type: **[HCURSOR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The new cursor shape.

### `bText`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** if the cursor is used for text, or **FALSE** if not.

## Return value

Type: **[HCURSOR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns the cursor that *hcur* is replacing.

## See also

[ITextHost2](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost2)

[ITextHost::TxSetCursor](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txsetcursor)

[ITextServices::OnTxSetCursor](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itextservices-ontxsetcursor)