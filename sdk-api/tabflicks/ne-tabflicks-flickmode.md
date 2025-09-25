# FLICKMODE enumeration

## Description

Describes where Flick gestures are enabled.

## Constants

### `FLICKMODE_MIN:0`

### `FLICKMODE_OFF:0`

Pen flicks are not enabled.

### `FLICKMODE_ON:1`

Pen flicks are enabled.

### `FLICKMODE_LEARNING:2`

### `FLICKMODE_MAX:2`

### `FLICKMODE_DEFAULT:1`

## Remarks

The **HKEY_CURRENT_USER\Software\Microsoft\Wisp\Pen\SysEventParameters** subkey has an entry called **FlickMode** that indicates whether pen flicks are enabled. The value of the entry is one of the **FLICKMODE** enumeration values.

## See also

[flicks gestures](https://learn.microsoft.com/windows/desktop/tablet/flicks-gestures)

[responding to pen flicks](https://learn.microsoft.com/previous-versions/windows/desktop/ms703447(v=vs.85))

[wm_tablet_flick message](https://learn.microsoft.com/windows/desktop/tablet/wm-tablet-flick-message)