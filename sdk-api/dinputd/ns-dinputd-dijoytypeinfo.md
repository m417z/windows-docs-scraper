# DIJOYTYPEINFO structure

## Description

The **DIJOYTYPEINFO** structure contains information about a joystick type.

## Members

### `dwSize`

Specifies the size of the structure in bytes. This member must be initialized before the structure is used.

### `hws`

Joystick hardware settings.

### `clsidConfig`

Specifies a CLSID for the joystick type configuration object. Pass this CLSID to CoCreateInstance to create a configuration object. This field is zero if the type does not have custom configuration.

### `wszDisplayName`

The display name for the joystick type. The display name is the name that should be used to display the name of the joystick type to the end user.

### `wszCallout`

The device responsible for handling polling for devices of this type. This is a null string if the global polling callout is to be used.

### `wszHardwareId`

The hardware ID for the joystick type. The hardware ID is used by Plug and Play on Windows 2000 and Windows 98 (DirectX 7.0 only) to find the drivers for the joystick.

### `dwFlags1`

Joystick type flags. This member can be set to a combination of the following flags.

#### JOYTYPE_ZEROGAMEENUMOEMDATA

Zero GameEnum's OEM data field.

#### JOYTYPE_NOAUTODETECTGAMEPORT

Device does not support Autodetect gameport.

#### JOYTYPE_NOHIDDIRECT

Do not use HID directly for this device. (Windows 98 only.)

#### JOYTYPE_DEFAULTPROPSHEET

CPL overrides custom property sheet.

### `dwFlags2`

Combination of device filtering and device type/subtype override flags. Device-filtering flags should be placed in the high WORD of **dwFlags2**. Device type and subtype should be placed in the low and high WORDs of the member, respectively.

#### Device Filtering Flags

Hide unclassified devices.

#### JOYTYPE_MOUSEHIDE

Hide mice.

#### JOYTYPE_KEYBHIDE

Hide keyboards.

#### JOYTYPE_GAMEHIDE

Hide game controllers.

#### JOYTYPE_HIDEACTIVE

Hide flags are active. This flag must be included if any other hide flags are specified.

#### Device Type and Subtype Override Flags

| Device Type | Device Subtype |
| --- | --- |
| DI8DEVTYPE_1STPERSON | DI8DEVTYPE1STPERSON_LIMITED |
|  | DI8DEVTYPE1STPERSON_UNKNOWN |
|  | DI8DEVTYPE1STPERSON_SIXDOF |
|  | DI8DEVTYPE1STPERSON_SHOOTER |
| DI8DEVTYPE_DEVICE | n/a |
| DI8DEVTYPE_DEVICECTRL | DI8DEVTYPEDEVICECTRL_UNKNOWN |
|  | DI8DEVTYPEDEVICECTRL_COMMSSELECTION |
|  | DI8DEVTYPEDEVICECTRL_COMMSSELECTION_HARDWIRED |
| DI8DEVTYPE_DRIVING | DI8DEVTYPEDRIVING_LIMITED |
|  | DI8DEVTYPEDRIVING_COMBINEDPEDALS |
|  | DI8DEVTYPEDRIVING_DUALPEDALS |
|  | DI8DEVTYPEDRIVING_THREEPEDALS |
|  | DI8DEVTYPEDRIVING_HANDHELD |
| DI8DEVTYPE_FLIGHT | DI8DEVTYPEFLIGHT_LIMITED |
|  | DI8DEVTYPEFLIGHT_STICK |
|  | DI8DEVTYPEFLIGHT_YOKE |
|  | DI8DEVTYPEFLIGHT_RC |
| DI8DEVTYPE_GAMEPAD | DI8DEVTYPEGAMEPAD_LIMITED |
|  | DI8DEVTYPEGAMEPAD_STANDARD |
|  | DI8DEVTYPEGAMEPAD_TILT |
| DI8DEVTYPE_JOYSTICK | DI8DEVTYPEJOYSTICK_LIMITED |
|  | DI8DEVTYPEJOYSTICK_STANDARD |
|  | DI8DEVTYPEJOYSTICK_ENHANCED |
| DI8DEVTYPE_KEYBOARD | DI8DEVTYPEKEYBOARD_UNKNOWN |
|  | DI8DEVTYPEKEYBOARD_PCXT |
|  | DI8DEVTYPEKEYBOARD_OLIVETTI |
|  | DI8DEVTYPEKEYBOARD_PCAT |
|  | DI8DEVTYPEKEYBOARD_PCENH |
|  | DI8DEVTYPEKEYBOARD_NOKIA1050 |
|  | DI8DEVTYPEKEYBOARD_NOKIA9140 |
|  | DI8DEVTYPEKEYBOARD_NEC98 |
|  | DI8DEVTYPEKEYBOARD_NEC98LAPTOP |
|  | DI8DEVTYPEKEYBOARD_NEC98106 |
|  | DI8DEVTYPEKEYBOARD_JAPAN106 |
|  | DI8DEVTYPEKEYBOARD_JAPANAX |
|  | DI8DEVTYPEKEYBOARD_J3100 |
| DI8DEVTYPE_MOUSE | DI8DEVTYPEMOUSE_UNKNOWN |
|  | DI8DEVTYPEMOUSE_TRADITIONAL |
|  | DI8DEVTYPEMOUSE_FINGERSTICK |
|  | DI8DEVTYPEMOUSE_TOUCHPAD |
|  | DI8DEVTYPEMOUSE_TRACKBALL |
|  | DI8DEVTYPEMOUSE_ABSOLUTE |
| DI8DEVTYPE_REMOTE | DI8DEVTYPEREMOTE_UNKNOWN |
| DI8DEVTYPE_SCREENPOINTER | DI8DEVTYPESCREENPTR_UNKNOWN |
|  | DI8DEVTYPESCREENPTR_LIGHTGUN |
|  | DI8DEVTYPESCREENPTR_LIGHTPEN |
|  | DI8DEVTYPESCREENPTR_TOUCH |
| DI8DEVTYPE_SUPPLEMENTAL | DI8DEVTYPESUPPLEMENTAL_UNKNOWN |
|  | DI8DEVTYPESUPPLEMENTAL_2NDHANDCONTROLLER |
|  | DI8DEVTYPESUPPLEMENTAL_HEADTRACKER |
|  | DI8DEVTYPESUPPLEMENTAL_HANDTRACKER |
|  | DI8DEVTYPESUPPLEMENTAL_SHIFTSTICKGATE |
|  | DI8DEVTYPESUPPLEMENTAL_SHIFTER |
|  | DI8DEVTYPESUPPLEMENTAL_THROTTLE |
|  | DI8DEVTYPESUPPLEMENTAL_SPLITTHROTTLE |
|  | DI8DEVTYPESUPPLEMENTAL_COMBINEDPEDALS |
|  | DI8DEVTYPESUPPLEMENTAL_DUALPEDALS |
|  | DI8DEVTYPESUPPLEMENTAL_THREEPEDALS |
|  | DI8DEVTYPESUPPLEMENTAL_RUDDERPEDALS |

### `wszMapFile`

## Remarks

A "joystick type" describes how DirectInput should communicate with the device and how it should report device data. For example, "A Frobozz Industries SuperStick 5X is a three-axis, five-button joystick with the third axis reported as the first bit on the second port."

DirectInput comes with the following predefined joystick types, all with axes in their default locations:

* Two-axis, two-button joystick.
* Two-button game pad.
* Two-button flight yoke.
* Two-button flight yoke with throttle.
* Three-axis, two-button joystick.
* Three-axis, four-button joystick.
* Four-button game pad.
* Four-button flight yoke.
* Four-button flight yoke with throttle.

If the joystick type has the JOY_HWS_ISGAMEPORTDRIVER flag set in the **dwFlags** member of the JOYHWSETTINGS structure, then the **wszCallout** member of the DIJOYTYPEINFO structure contains the name of a driver that can be used as a global driver. The joystick type should be shown on the list of global drivers and not shown on the list of joystick types that can be assigned.

**New in DirectX 8.0**

The **dwFlags2** member was added to the DIJOYCONFIG structure. This member carries information that controls how DirectInput enumerates the device to applications. The **dwFlags2** member carries device type and subtype override flags in the low word, and device enumeration "hiding" flags in the high word. The device type and subtype override flags control how DirectInput portrays your device to applications that use DirectInput. These are the same flags that applications receive from DirectInput during device enumeration. For example, if your device is described in its firmware as a telephony device, it would not normally be enumerated to games because telephony devices aren't considered relevant to games. However, if you used DI8DEVTYPE_DEVICECTRL and DI8DEVTYPEDEVICECONTROL_COMMSSELECTION to describe this device, DirectInput overrides the data it retrieves from the firmware and enumerates the device to games.

The high word of **dwFlags2** can be set to contain flags that scope how DirectInput enumerates the device to DirectInput applications. For example, some devices declare multiple top-level HID collections. Such a device might declare that it can act as a keyboard, a mouse, and a joystick all in one. Generally, one or more of these top-level collections is merely a phantom device, which shouldn't be enumerated to games. For this device, the high word of **dwFlags2** could be set to a combination of the JOYTYPE_HIDEACTIVE, JOYTYPE_MOUSEHIDE, and JOYTYPE_KEYBHIDE flags. The JOYTYPE_HIDEACTIVE flag indicates that DirectInput should not enumerate the device by all its types. The JOYTYPE_MOUSEHIDE and JOYTYPE_KEYBHIDE flags also present in the high word indicate to DirectInput that enumeration of the phantom mouse and keyboard on the device should be suppressed. Note that applications can include the DIEDFL_INCLUDEHIDDEN (described in the Microsoft Windows SDK documentation) flag to enumerate devices, even if they are hidden.