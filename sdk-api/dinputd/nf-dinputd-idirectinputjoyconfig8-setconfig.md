# IDirectInputJoyConfig8::SetConfig

## Description

The **IDirectInputJoyConfig8::SetConfig**  method creates or redefines configuration information about a joystick.

## Parameters

### `unnamedParam1`

Indicates a zero-based joystick identification number.

### `unnamedParam2`

Contains information about the joystick.

### `unnamedParam3`

Specifies the parts of the [DIJOYCONFIG](https://learn.microsoft.com/windows/desktop/api/dinputd/ns-dinputd-dijoyconfig) structure pointed to by *pcfg* that contain information to be set. There may be zero, one, or more of the following:

#### DIJC_REGHWCONFIGTYPE

Indicates that the hardware configuration for the joystick (the **hwc** member of the DIJOYCONFIG structure) and the joystick type name (the **wszType** member of the DIJOYCONFIG) are valid. Note that the hardware configuration and type name cannot be set separately.

#### DIJC_GAIN

Indicates that the force-feedback gain for the joystick is valid.

#### DIJC_CALLOUT

Indicates that the joystick polling callout is valid.

## Return value

Returns DI_OK if successful; otherwise, returns one of the following COM error values:

| Return code | Description |
| --- | --- |
| **DIERR_NOTACQUIRED** | Joystick configuration has not been acquired. You must call [IDirectInputJoyConfig8::Acquire](https://learn.microsoft.com/windows/desktop/api/dinputd/nf-dinputd-idirectinputjoyconfig8-acquire) before you can notify applications and drivers of changes to joystick configuration. |
| **DIERR_INVALIDPARAM** | One or more parameters was invalid. |