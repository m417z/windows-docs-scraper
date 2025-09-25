# HHNTRACK structure

## Description

This structure returns the file name of the current topic and a constant that specifies the user action that is about to occur, such as hiding the Navigation pane by clicking the Hide button on the toolbar.

## Members

### `hdr`

Standard **WM_NOTIFY** header.

### `pszCurUrl`

A multi-byte, zero-terminated string that specifies the current topic (before the action is taken).

### `idAction`

Specifies the action the user is about to take. This is an [HHACT_](https://learn.microsoft.com/previous-versions/windows/desktop/htmlhelp/idaction-member) constant.

### `phhWinType`

A pointer to the current [HH_WINTYPE](https://learn.microsoft.com/windows/desktop/api/htmlhelp/ns-htmlhelp-hh_wintype) structure.

## See also

[About structures](https://learn.microsoft.com/previous-versions/windows/desktop/htmlhelp/about-structures)