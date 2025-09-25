# NMPGHOTITEM structure

## Description

Contains information used with the [PGN_HOTITEMCHANGE](https://learn.microsoft.com/windows/desktop/Controls/pgn-hotitemchange) notification code.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains additional information about the notification.

### `idOld`

Type: **int**

Value of type **int** that specifies the command identifier of the previously highlighted item.

### `idNew`

Type: **int**

Value of type **int** that specifies the command identifier of the highlighted item.

### `dwFlags`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**DWORD** that contains flags that indicate why the hot item has changed. This can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| HICF_ENTERING | If this flag is set, there is no previous hot item and **idOld** does not contain valid information. |
| HICF_LEAVING | If this flag is set, there is no new hot item and **idNew** does not contain valid information. |