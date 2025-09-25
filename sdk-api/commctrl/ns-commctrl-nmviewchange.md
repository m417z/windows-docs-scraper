# NMVIEWCHANGE structure

## Description

Stores information required to process the [MCN_VIEWCHANGE](https://learn.microsoft.com/windows/desktop/Controls/mcn-viewchange) notification code.

## Members

### `nmhdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains information about this notification code.

### `dwOldView`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Old view. One of the following constants.

| Value | Meaning |
| --- | --- |
| **MCMV_MONTH** | Monthly view. |
| **MCMV_YEAR** | Annual view. |
| **MCMV_DECADE** | Decade view. |
| **MCMV_CENTURY** | Century view. |

### `dwNewView`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

New view. One of the constants listed at **dwOldView**.