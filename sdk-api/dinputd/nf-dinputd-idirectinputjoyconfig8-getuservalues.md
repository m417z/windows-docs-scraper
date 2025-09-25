# IDirectInputJoyConfig8::GetUserValues

## Description

The **IDirectInputJoyConfig8::GetUserValues**  method obtains information about user settings for the joystick.

## Parameters

### `unnamedParam1`

Points to a structure that receives information about the user joystick configuration. The caller must initialize the **dwSize** member of the [DIJOYUSERVALUES](https://learn.microsoft.com/windows/desktop/api/dinputd/ns-dinputd-dijoyuservalues) structure before calling this method.

### `unnamedParam2`

Specifies which members of the DIJOYUSERVALUES structure contain values to be retrieved. There may be zero, one, or more of the following:

#### DIJU_USERVALUES

Indicates that the user configuration settings (the **ruv** member of the DIJOYUSERVALUES structure) is being requested.

#### DIJU_GLOBALDRIVER

Indicates that the global port driver (the **wszGlobalDriver** member of the DIJOYUSERVALUES structure) is being requested.

A list of valid global drivers can be obtained by enumerating the list of joystick types. If the joystick type has the JOY_HWS_ISGAMEPORTDRIVER flag set in the **dwFlags** member of the JOYHWSETTINGS structure, then the **wszCallout** member of the [DIJOYTYPEINFO](https://learn.microsoft.com/windows/desktop/api/dinputd/ns-dinputd-dijoytypeinfo) structure contains the name of a driver that can be used as a global driver.

#### DIJU_GAMEPORTEMULATOR

Unused

## Return value

Returns DI_OK if successful; otherwise, returns the following COM error value:

| Return code | Description |
| --- | --- |
| **DIERR_INVALIDPARAM** | One or more parameters was invalid. |