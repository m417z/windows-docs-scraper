# joyGetNumDevs function

## Description

The **joyGetNumDevs** function queries the joystick driver for the number of joysticks it supports.

## Return value

The **joyGetNumDevs** function returns the number of joysticks supported by the current driver or zero if no driver is installed.

## Remarks

Use the [joyGetPos](https://learn.microsoft.com/previous-versions/dd757107(v=vs.85)) function to determine whether a given joystick is physically attached to the system. If the specified joystick is not connected, **joyGetPos** returns a JOYERR_UNPLUGGED error value.

## See also

[Joysticks](https://learn.microsoft.com/windows/desktop/Multimedia/joysticks)

[Multimedia Joystick Functions](https://learn.microsoft.com/windows/desktop/Multimedia/multimedia-joystick-functions)