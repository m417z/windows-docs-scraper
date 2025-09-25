# ITextHost2::TxGetEditStyle

## Description

Gets whether a rich edit control is in a dialog box.

## Parameters

### `dwItem`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Mask that indicates the edit style flags to retrieve. It can be the following value.

#### TXES_ISDIALOG

### `pdwData`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

| Value | Meaning |
| --- | --- |
| **TXES_ISDIALOG** | Indicates that the host of the rich edit control is a dialog box. |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextHost2](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost2)