# DIJOYCONFIG structure

## Description

The DIJOYCONFIG structure contains information about a joystick's configuration.

## Members

### `dwSize`

Specifies the size of the structure in bytes. This member must be initialized before the structure is used.

### `guidInstance`

Specifies the instance GUID for the joystick.

### `hwc`

Joystick hardware configuration.

### `dwGain`

Specifies the global gain setting. This value is applied to all force feedback effects as a "master volume control".

### `wszType`

The joystick type for the joystick. It must be one of the values enumerated by [IDirectInputJoyConfig8::EnumTypes](https://learn.microsoft.com/windows/desktop/api/dinputd/nf-dinputd-idirectinputjoyconfig8-enumtypes).

### `wszCallout`

The callout driver for the joystick.

### `guidGameport`

Specifies a GUID that identifies the gameport being used for this joystick.

## Remarks

WDM gameports can be found during enumeration by calling [IDirectInputJoyConfig8::GetTypeInfo](https://learn.microsoft.com/windows/desktop/api/dinputd/nf-dinputd-idirectinputjoyconfig8-gettypeinfo) method for an enumerated joystick, then studying the flags present in the **dwFlags** member of the [DIJOYTYPEINFO](https://learn.microsoft.com/windows/desktop/api/dinputd/ns-dinputd-dijoytypeinfo) structure. If the JOY_HWS_ISGAMEPORTBUS flag is set, the currently enumerated object is an available WDM gameport.