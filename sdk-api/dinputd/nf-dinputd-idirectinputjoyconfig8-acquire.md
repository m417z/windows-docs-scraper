# IDirectInputJoyConfig8::Acquire

## Description

The **IDirectInputJoyConfig8::Acquire**  method acquires "joystick configuration mode." Only one application can be in joystick configuration mode at a time; subsequent attempts by other applications to acquire this mode should receive the error DIERR_OTHERAPPHASPRIO. After entering configuration mode, the application can make alterations to the global joystick configuration settings. The application should check the existing settings before installing the new ones in case another application changed the settings in the interim.

## Return value

Returns DI_OK if successful; otherwise, returns one of the following COM error values:

| Return code | Description |
| --- | --- |
| **DIERR_OTHERAPPHASPRIO** | Another application is already in joystick configuration mode. |
| **DIERR_INSUFFICIENTPRIVS** | The current user does not have the necessary permissions to alter the joystick configuration. |
| **DIERR_DEVICECHANGE** | Another application has changed the global joystick configuration. The interface needs to be reinitialized. |