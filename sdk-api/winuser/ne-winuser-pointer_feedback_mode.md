# POINTER_FEEDBACK_MODE enumeration

## Description

Identifies the visual feedback behaviors available to [CreateSyntheticPointerDevice](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-createsyntheticpointerdevice).

## Constants

### `POINTER_FEEDBACK_DEFAULT:1`

Visual feedback might be suppressed by the user's pen (Settings -> Devices -> Pen & Windows Ink) and touch (Settings -> Ease of Access -> Cursor & pointer size) settings.

### `POINTER_FEEDBACK_INDIRECT:2`

Visual feedback overrides the user's pen and touch settings.

### `POINTER_FEEDBACK_NONE:3`

Visual feedback is disabled.