# IDirectInputJoyConfig8::SendNotify

## Description

The **IDirectInputJoyConfig8::SendNotify**  method notifies device drivers and applications that changes to the device configuration have been made. An application that changes device configurations must invoke this method after the changes have been made (and before unacquiring the device).

## Return value

Returns DI_OK if successful; otherwise, returns the following COM error value (this value is intended to be illustrative and is not necessarily comprehensive):

| Return code | Description |
| --- | --- |
| **DIERR_NOTACQUIRED** | Joystick configuration has not been acquired. You must call [IDirectInputJoyConfig8::Acquire](https://learn.microsoft.com/windows/desktop/api/dinputd/nf-dinputd-idirectinputjoyconfig8-acquire) before you can notify applications and drivers of changes to joystick configuration. |