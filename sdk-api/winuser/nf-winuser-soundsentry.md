# SoundSentry function

## Description

Triggers a visual signal to indicate that a sound is playing.

## Return value

Type: **BOOL**

This function returns one of the following values.

| Return code | Description |
| --- | --- |
| **TRUE** | The visual signal was or will be displayed correctly. |
| **FALSE** | An error prevented the signal from being displayed. |

## Remarks

Set the notification behavior by calling [SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa) with the **SPI_SETSOUNDSENTRY** value.

## See also

**Reference**

[SOUNDSENTRY](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-soundsentrya)

[SoundSentryProc](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd373647(v=vs.85))