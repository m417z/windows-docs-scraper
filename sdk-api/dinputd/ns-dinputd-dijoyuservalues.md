# DIJOYUSERVALUES structure

## Description

The **DIJOYUSERVALUES** structure contains information about the user's joystick settings.

## Members

### `dwSize`

Specifies the size of the structure in bytes. This member must be initialized before the structure is used.

### `ruv`

Joystick user configuration. In addition to the fields contained in the mmddk.h header file, the previously unused **jrvRanges.jpCenter** field contains the user saturation levels for each axis. A control panel application sets the dead zone and saturation values based on the values set by the end-user during calibration or fine-tuning. Dead zone can be interpreted as "sensitivity in the center" and saturation can be interpreted as "sensitivity along the edges".

### `wszGlobalDriver`

The global port driver.

### `wszGameportEmulator`

Unused.