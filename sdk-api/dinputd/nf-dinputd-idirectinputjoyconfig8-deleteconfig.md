## Description

The **IDirectInputJoyConfig8::DeleteConfig**  method deletes configuration information about a joystick.

## Parameters

### `unnamedParam1`

Indicates a zero-based joystick identification number.

## Return value

Returns DI_OK if successful; otherwise, returns one of the following COM error values (these values are intended to be illustrative and are not necessarily comprehensive):

| Return code | Description |
| --- | --- |
| **DIERR_NOTACQUIRED** | Joystick configuration has not been acquired. You must call [IDirectInputJoyConfig8::Acquire](https://learn.microsoft.com/windows/desktop/api/dinputd/nf-dinputd-idirectinputjoyconfig8-acquire) before you can alter joystick configuration settings. |
| **DIERR_INVALIDPARAM** | One or more parameters was invalid. |