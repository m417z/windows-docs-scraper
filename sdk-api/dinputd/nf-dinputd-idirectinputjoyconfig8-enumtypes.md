# IDirectInputJoyConfig8::EnumTypes

## Description

The **IDirectInputJoyConfig8::EnumTypes**  method enumerates the joystick types currently supported by DirectInput. A joystick type describes how DirectInput should communicate with a joystick device. It includes information such as the presence and location of each of the axes and the number of buttons supported by the device.

## Parameters

### `unnamedParam1`

Points to an application-defined callback function that receives the DirectInput joystick types. See the Remarks section for the function prototype.

### `unnamedParam2`

Specifies a 32-bit application-defined value to be passed to the callback function. This value can be any 32-bit value; it is prototyped as an LPVOID for convenience.

## Return value

Returns DI_OK if successful; otherwise, returns one of the following COM error values:

| Return code | Description |
| --- | --- |
| **DIERR_INVALIDPARAM** | One or more parameters was invalid. |

## Remarks

This callback receives DirectInput joystick types as a result of a call to the IDirectInputJoyConfig8::EnumTypes method.

``` syntax

/*
Parameters
pwszTypeName
Points to the name of the joystick type. A buffer of MAX_JOYSTRING characters is sufficient to hold the type name. The type name should never be shown to the end user; instead, the "display name" should be shown. Use IDirectInputJoyConfig8::GetTypeInfo to obtain the display name of a joystick type. Type names that begin with a pound sign ("#") represent predefined types that cannot be modified or deleted.

pvRef
Points to the application-defined value given in the IDirectInputJoyConfig8::EnumTypes method.

Return value
Returns a BOOL value, DIENUM_CONTINUE, to continue the enumeration, or DIENUM_STOP to stop the enumeration.

*/

BOOL DIEnumJoyTypeProc(
   LPCWSTR pwszTypeName,
   LPVOID  pvRef
);

```