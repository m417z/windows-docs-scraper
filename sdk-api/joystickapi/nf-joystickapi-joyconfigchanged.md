# joyConfigChanged function

## Description

The **joyConfigChanged** function informs the joystick driver that the configuration has changed and should be reloaded from the registry.

## Parameters

### `dwFlags`

Reserved for future use. Must equal zero.

## Return value

Returns JOYERR_NOERROR if successful. Returns JOYERR_PARMS if the parameter is non-zero.

## Remarks

This function causes a window message to be sent to all top-level windows. This message may be defined by applications that need to respond to changes in joystick calibration by using **RegisterWindowMessage** with the following message ID:

```cpp

#define JOY_CONFIGCHANGED_MSGSTRING     "MSJSTICK_VJOYD_MSGSTR"

```

## See also

[Joysticks](https://learn.microsoft.com/windows/desktop/Multimedia/joysticks)

[Multimedia Joystick Functions](https://learn.microsoft.com/windows/desktop/Multimedia/multimedia-joystick-functions)