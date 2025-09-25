## Description

The **IDirectInputJoyConfig8::DeleteType**  method removes information about a joystick type. Use this method with caution; it is the caller's responsibility to ensure that no joystick refers to the deleted type.

## Parameters

### `unnamedParam1`

Points to the name of the type. The name of the type cannot exceed MAX_PATH characters, including the terminating null character. Also, the name cannot begin with a "#" character. Types beginning with "#" are reserved by DirectInput.

## Return value

Returns DI_OK if successful; otherwise, returns one of the following COM error values (these values are intended to be illustrative and are not necessarily comprehensive):

| Return code | Description |
| --- | --- |
| **DIERR_NOTACQUIRED** | Joystick configuration has not been acquired. You must call [IDirectInputJoyConfig8::Acquire](https://learn.microsoft.com/windows/desktop/api/dinputd/nf-dinputd-idirectinputjoyconfig8-acquire) before you can alter joystick configuration settings. |
| **DIERR_INVALIDPARAM** | One or more parameters was invalid. |