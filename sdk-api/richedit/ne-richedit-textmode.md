# TEXTMODE enumeration

## Description

Indicates the text mode of a rich edit control. The [EM_SETTEXTMODE](https://learn.microsoft.com/windows/win32/controls/em-settextmode) and [EM_GETTEXTMODE](https://learn.microsoft.com/windows/win32/controls/em-gettextmode) messages use this enumeration type.

## Constants

### `TM_PLAINTEXT:1`

Indicates plain-text mode, in which the control is similar to a standard edit control. For more information about plain-text mode, see the Remarks section of [EM_SETTEXTMODE](https://learn.microsoft.com/windows/win32/controls/em-settextmode).

### `TM_RICHTEXT:2`

Indicates rich-text mode, in which the control has the standard rich edit functionality. Rich-text mode is the default setting.

### `TM_SINGLELEVELUNDO:4`

The control allows the user to undo only the last action in the undo queue.

### `TM_MULTILEVELUNDO:8`

The control supports multiple undo actions. This is the default setting. Use the [EM_SETUNDOLIMIT](https://learn.microsoft.com/windows/win32/controls/em-setundolimit) message to set the maximum number of undo actions.

### `TM_SINGLECODEPAGE:16`

The control only allows the English keyboard and a keyboard corresponding to the default character set. For example, you could have Greek and English. Note that this prevents Unicode text from entering the control. For example, use this value if a Rich Edit control must be restricted to ANSI text.

### `TM_MULTICODEPAGE:32`

The control allows multiple code pages and Unicode text into the control. This is the default setting.

## See also

[EM_GETTEXTMODE](https://learn.microsoft.com/windows/win32/controls/em-gettextmode)

[EM_SETTEXTMODE](https://learn.microsoft.com/windows/win32/controls/em-settextmode)

**Reference**