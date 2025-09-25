# IDirectInputJoyConfig8::SetTypeInfo

## Description

The **IDirectInputJoyConfig8::SetTypeInfo**  method creates a new joystick type or redefines information about an existing joystick type.

## Parameters

### `unnamedParam1`

Points to the name of the type. The name of the type cannot exceed MAX_JOYSTRING characters, including the terminating null character. If the type name does not already exist, then it is created. You cannot change the type information for a predefined type. The name cannot begin with a "#" character. Types beginning with "#" are reserved by DirectInput.

### `unnamedParam2`

Points to a structure that receives information about the joystick type.

### `unnamedParam3`

Specifies the parts of the [DIJOYTYPEINFO](https://learn.microsoft.com/windows/desktop/api/dinputd/ns-dinputd-dijoytypeinfo) structure pointed to by *pjti* that contain values to be set.

#### DITC_REGHWSETTINGS

Indicates that the registry hardware settings for the joystick are valid.

#### DITC_CLSIDCONFIG

Indicates that the joystick configuration CLSID is valid. If the value is all zeros, then there is no custom configuration for this joystick type.

#### DITC_DISPLAYNAME

Indicates that the display name for the joystick type is valid.

#### DITC_CALLOUT

Indicates that the callout for the joystick type is valid.

### `unnamedParam4`

If the type name is an OEM type not in VID_xxxx&PID_yyyy format, this parameter will return the name in VID_xxxx&PID_yyyy format that is assigned by Dinput.
This VID_xxxx&PID_yyyy name should be used in DIJOYCONFIG.wszType field when calling SetConfig.

## Return value

Returns DI_OK if successful; otherwise, returns one of the following COM error values:

| Return code | Description |
| --- | --- |
| **DIERR_NOTACQUIRED** | Joystick configuration has not been acquired. You must call [IDirectInputJoyConfig8::Acquire](https://learn.microsoft.com/windows/desktop/api/dinputd/nf-dinputd-idirectinputjoyconfig8-acquire) before you can notify applications and drivers of changes to joystick configuration. |
| **DIERR_INVALIDPARAM** | One or more parameters was invalid. |
| **DIERR_READONLY** | Attempted to change a predefined type. |