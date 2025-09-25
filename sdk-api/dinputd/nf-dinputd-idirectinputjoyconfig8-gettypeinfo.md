# IDirectInputJoyConfig8::GetTypeInfo

## Description

The **IDirectInputJoyConfig8::GetTypeInfo**  method obtains information about a joystick type.

## Parameters

### `unnamedParam1`

Points to the name of the type, previously obtained from a call to [IDirectInputJoyConfig8::EnumTypes](https://learn.microsoft.com/windows/desktop/api/dinputd/nf-dinputd-idirectinputjoyconfig8-enumtypes).

### `unnamedParam2`

Points to a structure that receives information about the joystick type. The caller must initialize the **dwSize** member of the [DIJOYTYPEINFO](https://learn.microsoft.com/windows/desktop/api/dinputd/ns-dinputd-dijoytypeinfo) structure before calling this method.

### `unnamedParam3`

Specifies the parts of the DIJOYTYPEINFO structure pointed to by *pjti* that are to be filled. There may be zero, one, or more of the following:

#### DITC_REGHWSETTINGS

Indicates that the registry hardware settings for the joystick are being requested.

#### DITC_CLSIDCONFIG

Indicates that the joystick configuration CLSID is being requested. If the value is all zeros, then there is no custom configuration for this joystick type.

#### DITC_DISPLAYNAME

Indicates that the display name for the joystick type is being requested.

#### DITC_CALLOUT

Indicates that the callout for the joystick type is being requested.

## Return value

Returns DI_OK if successful; otherwise, returns one of the following COM error values:

| Return code | Description |
| --- | --- |
| **DIERR_INVALIDPARAM** | One or more parameters was invalid. |
| **DIERR_NOTFOUND** | The joystick type was not found. |