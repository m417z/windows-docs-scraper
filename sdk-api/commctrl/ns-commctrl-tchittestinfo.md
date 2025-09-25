# TCHITTESTINFO structure

## Description

Contains information about a hit test. This structure supersedes the
**TC_HITTESTINFO** structure.

## Members

### `pt`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

Position to hit test, in client coordinates.

### `flags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Variable that receives the results of a hit test. The tab control sets this member to one of the following values:

| Value | Meaning |
| --- | --- |
| **TCHT_NOWHERE** | The position is not over a tab. |
| **TCHT_ONITEM** | The position is over a tab but not over its icon or its text. For owner-drawn tab controls, this value is specified if the position is anywhere over a tab. |
| **TCHT_ONITEMICON** | The position is over a tab's icon. |
| **TCHT_ONITEMLABEL** | The position is over a tab's text. |
|  | TCHT_ONITEM is a bitwise-OR operation on TCHT_ONITEMICON and TCHT_ONITEMLABEL. |

## See also

[TCM_HITTEST](https://learn.microsoft.com/windows/desktop/Controls/tcm-hittest)