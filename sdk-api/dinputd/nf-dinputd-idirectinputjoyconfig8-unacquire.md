# IDirectInputJoyConfig8::Unacquire

## Description

The **IDirectInputJoyConfig8::Unacquire**  method unacquires "joystick configuration mode".

## Return value

Returns DI_OK if successful; otherwise, returns a COM error code.

## Remarks

Before unacquiring configuration mode, the application performs an [IDirectInputJoyConfig8::SendNotify](https://learn.microsoft.com/windows/desktop/api/dinputd/nf-dinputd-idirectinputjoyconfig8-sendnotify) to propagate the changes in the joystick configuration to all device drivers and applications. Applications that hold interfaces to a joystick that is materially affected by a change in configuration should receive the DIERR_DEVICECHANGE error code until the device is reinitialized. Examples of material changes to configuration include altering the number of axes or the number of buttons. In comparison, changes to device calibration are handled internally by DirectInput and are transparent to the application.