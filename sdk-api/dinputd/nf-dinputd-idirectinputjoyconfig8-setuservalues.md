# IDirectInputJoyConfig8::SetUserValues

## Description

The **IDirectInputJoyConfig8::SetUserValues**  method sets the user settings for the joystick.

## Parameters

### `unnamedParam1`

Points to a structure that receives information about the new user joystick settings.

### `unnamedParam2`

Specifies the parts of the [DIJOYUSERVALUES](https://learn.microsoft.com/windows/desktop/api/dinputd/ns-dinputd-dijoyuservalues) structure that contain values to be set. There may be zero, one, or more of the following:

#### DIJU_USERVALUES

Indicates that the user configuration settings (the **ruv** member of the DIJOYUSERVALUES structure) is valid.

#### DIJU_GLOBALDRIVER

Indicates that the global port driver (the **wszGlobalDriver** member of the DIJOYUSERVALUES structure) is valid.

A list of valid global drivers can be obtained by enumerating the list of joystick types. If the joystick type has the JOY_HWS_ISGAMEPORTDRIVER flag set in the **dwFlags** member of the JOYHWSETTINGS structure, then the **wszCallout** member of the [DIJOYTYPEINFO](https://learn.microsoft.com/windows/desktop/api/dinputd/ns-dinputd-dijoytypeinfo) structure contains the name of a driver that can be used as a global driver.

#### DIJU_GAMEPORTEMULATOR

Unused.

## Return value

Returns DI_OK if successful; otherwise, returns one of the following COM error values:

| Return code | Description |
| --- | --- |
| **DIERR_NOTACQUIRED** | Joystick configuration has not been acquired. You must call [IDirectInputJoyConfig8::Acquire](https://learn.microsoft.com/windows/desktop/api/dinputd/nf-dinputd-idirectinputjoyconfig8-acquire) before you can notify applications and drivers of changes to joystick configuration. |
| **DIERR_INVALIDPARAM** | One or more parameters was invalid. |