# IDirectInputJoyConfig8::GetConfig

## Description

The **IDirectInputJoyConfig8::GetConfig**  method obtains information about a joystick's configuration.

## Parameters

### `unnamedParam1`

Indicates a joystick identification number. This is a nonnegative integer. To enumerate joysticks, begin with joystick zero and increment the joystick number by one until the function returns DIERR_NOMOREITEMS.

### `unnamedParam2`

Points to a structure that receives information about the joystick configuration. The caller "must" initialize the **dwSize** member of the [DIJOYCONFIG](https://learn.microsoft.com/windows/desktop/api/dinputd/ns-dinputd-dijoyconfig) structure before calling this method.

### `unnamedParam3`

Specifies the members of the structure pointed to by *pjc* that are to be filled in. This parameter can be zero, one, or more of the following:

#### DIJC_GUIDINSTANCE

Indicates that the instance GUID for the joystick is being requested. An application can pass the instance GUID to **IDirectInput::CreateDevice** to obtain an **IDirectInputDevice** interface to the joystick. Note that this flag is not a valid parameter for **IDirectInputJoyConfig8::SetConfig**.

#### DIJC_REGHWCONFIGTYPE

Indicates that the hardware configuration for the joystick (the **hwc** member of the DIJOYCONFIG structure) and the joystick type name (the **wszType** member of the same structure) are being requested. Note that the hardware configuration and type name cannot be retrieved separately.

#### DIJC_GAIN

Indicates that the force-feedback gain for the joystick is being requested.

#### DIJC_CALLOUT

Indicates that the joystick polling callout is being requested.

## Return value

Returns DI_OK if successful; otherwise, returns one of the following COM error values:

| Return code | Description |
| --- | --- |
| **DIERR_INVALIDPARAM** | One or more parameters was invalid. |
| **S_FALSE** | The specified joystick has not yet been configured. |
| **DIERR_NOMOREITEMS** | No more joysticks are available. |