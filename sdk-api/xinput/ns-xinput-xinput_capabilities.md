# XINPUT_CAPABILITIES structure

## Description

Describes the capabilities of a connected controller. The [XInputGetCapabilities](https://learn.microsoft.com/windows/desktop/api/xinput/nf-xinput-xinputgetcapabilities) function returns **XINPUT_CAPABILITIES**.

## Members

### `Type`

Controller type. It must be one of the following values.

| Value | Description |
| --- | --- |
| XINPUT_DEVTYPE_GAMEPAD | The device is a game controller. |

### `SubType`

Subtype of the game controller. See [XINPUT and Controller Subtypes](https://learn.microsoft.com/windows/desktop/xinput/xinput-and-controller-subtypes) for a list of allowed subtypes.

**Note** For restrictions on the use of this subtype value, see Remarks. More subtypes may be added in the future.

### `Flags`

Features of the controller.

| Value | Description |
| --- | --- |
| XINPUT_CAPS_VOICE_SUPPORTED | Device has an integrated voice device. |
| XINPUT_CAPS_FFB_SUPPORTED | Device supports force feedback functionality. Note that these force-feedback features beyond rumble are not currently supported through XINPUT on Windows. |
| XINPUT_CAPS_WIRELESS | Device is wireless. |
| XINPUT_CAPS_PMD_SUPPORTED | Device supports plug-in modules. Note that plug-in modules like the text input device (TID) are not supported currently through XINPUT on Windows. |
| XINPUT_CAPS_NO_NAVIGATION | Device lacks menu navigation buttons (START, BACK, DPAD). |

### `Gamepad`

[XINPUT_GAMEPAD](https://learn.microsoft.com/windows/desktop/api/xinput/ns-xinput-xinput_gamepad) structure that describes available controller features and control resolutions.

### `Vibration`

[XINPUT_VIBRATION](https://learn.microsoft.com/windows/desktop/api/xinput/ns-xinput-xinput_vibration) structure that describes available vibration functionality and resolutions.

## Remarks

[XInputGetCapabilities](https://learn.microsoft.com/windows/desktop/api/xinput/nf-xinput-xinputgetcapabilities) returns **XINPUT_CAPABILITIES** to indicate the characteristics and available functionality of a specified controller.

[XInputGetCapabilities](https://learn.microsoft.com/windows/desktop/api/xinput/nf-xinput-xinputgetcapabilities) sets the structure members to indicate which inputs the device supports. For binary state controls, such as digital buttons, the corresponding bit reflects whether or not the control is supported by the device. For proportional controls, such as thumbsticks, the value indicates the resolution for that control. Some number of the least significant bits may not be set, indicating that the control does not provide resolution to that level.

The *SubType* member indicates the specific subtype of controller present. Games may detect the controller subtype and tune their handling of controller input or output based on subtypes that are well suited to their game genre. For example, a car racing game might check for the presence of a wheel controller to provide finer control of the car being driven. However, titles must not disable or ignore a device based on its subtype. Subtypes not recognized by the game or for which the game is not specifically tuned should be treated as a standard controller (XINPUT_DEVSUBTYPE_GAMEPAD).

Older XUSB Windows drivers report incomplete capabilities information, particularly for wireless devices. The latest XUSB Windows driver provides full support for wired and wireless devices, and more complete and accurate capabilities flags.

## See also

[XINPUT_GAMEPAD](https://learn.microsoft.com/windows/desktop/api/xinput/ns-xinput-xinput_gamepad)

[XINPUT_VIBRATION](https://learn.microsoft.com/windows/desktop/api/xinput/ns-xinput-xinput_vibration)

[XInput Structures](https://learn.microsoft.com/windows/desktop/xinput/structures)

[XInputGetCapabilities](https://learn.microsoft.com/windows/desktop/api/xinput/nf-xinput-xinputgetcapabilities)