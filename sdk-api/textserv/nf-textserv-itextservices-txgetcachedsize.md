# ITextServices::TxGetCachedSize

## Description

Returns the cached drawing logical size (if any) that text services is using. Typically, this will be the size of the last client rectangle used in [ITextServices::TxDraw](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itextservices-txdraw), [ITextServices::OnTxSetCursor](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itextservices-ontxsetcursor), and so forth, although it is not guaranteed to be.

## Parameters

### `pdwWidth` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The width, in client coordinates.

### `pdwHeight` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The height (in client coordinates).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, the return value is an **HRESULT** code.

## Remarks

This method can free the host from the need to maintain the cached drawing size information and the need to keep in synchronization.

## See also

**Conceptual**

[ITextServices](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itextservices)

[OnTxSetCursor](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itextservices-ontxsetcursor)

**Reference**

[TxDraw](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itextservices-txdraw)

[Windowless Rich Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)