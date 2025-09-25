# IMECOMPOSITIONSTRINGINFO structure

## Description

Contains information of IME's composition string in an app.

## Members

### `iCompStrLen`

Length (number of **WCHAR**s) of composition string.

### `iCaretPos`

Caret position of composition string.

### `iEditStart`

Position of composition string that is editable.

### `iEditLen`

Length of composition string that is editable.

### `iTargetStart`

Start position of target phrase of composition string.

### `iTargetLen`

Target phrase length of composition string.

## See also

[IImePad::Request](https://learn.microsoft.com/windows/desktop/api/imepad/nf-imepad-iimepad-request)