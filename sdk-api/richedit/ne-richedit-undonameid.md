# UNDONAMEID enumeration

## Description

Contains values that indicate types of rich edit control actions that can be undone or redone. The [EM_GETREDONAME](https://learn.microsoft.com/windows/win32/controls/em-getredoname) and [EM_GETUNDONAME](https://learn.microsoft.com/windows/win32/controls/em-getundoname) messages use this enumeration type to return a value.

## Constants

### `UID_UNKNOWN:0`

The type of undo action is unknown.

### `UID_TYPING:1`

Typing operation.

### `UID_DELETE:2`

Delete operation.

### `UID_DRAGDROP:3`

Drag-and-drop operation.

### `UID_CUT:4`

Cut operation.

### `UID_PASTE:5`

Paste operation.

### `UID_AUTOTABLE:6`

Automatic table insertion; for example, typing +---+---+<Enter> to insert a table row.

## See also

[EM_GETREDONAME](https://learn.microsoft.com/windows/win32/controls/em-getredoname)

[EM_GETUNDONAME](https://learn.microsoft.com/windows/win32/controls/em-getundoname)

**Reference**