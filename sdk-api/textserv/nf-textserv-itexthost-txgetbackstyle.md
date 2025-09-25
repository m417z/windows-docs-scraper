# ITextHost::TxGetBackStyle

## Description

Requests the background style of the text host.

## Parameters

### `pstyle`

Type: **TXTBACKSTYLE***

A variable that the text host sets to indicate the background style. The style is one of the following values from the
**TXTBACKSTYLE** enumeration.

| Value | Meaning |
| --- | --- |
| **TXTBACK_TRANSPARENT** | Background shows through. |
| **TXTBACK_OPAQUE** | Background does not show through. |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The return value is **S_OK**.

## See also

[ITextHost](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost)

[Windowless Rich Edit Controls Overview](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)