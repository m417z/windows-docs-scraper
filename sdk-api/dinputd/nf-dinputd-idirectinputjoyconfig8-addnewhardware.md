# IDirectInputJoyConfig8::AddNewHardware

## Description

The **IDirectInputJoyConfig8::AddNewHardware**  method displays the **Add New Hardware** dialog box which guides the user through installing a new input device.

## Parameters

### `unnamedParam1`

Handle to the window that functions as the owner window for the user interface.

### `unnamedParam2`

GUID that specifies the class of the hardware device to be added. DirectInput comes with the following class GUIDs already defined:

#### GUID_KeyboardClass

Keyboard devices.

#### GUID_MouseClass

Mouse devices.

#### GUID_MediaClass

Media devices, including joysticks.

#### GUID_HIDClass

HID devices.

## Return value

Returns DI_OK if successful; otherwise, returns one of the following COM error values:

| Return code | Description |
| --- | --- |
| **DIERR_INVALIDPARAM** | (E_INVALIDARG). One or more parameters was invalid. |
| **DIERR_INVALIDCLASSINSTALLER** | The class installer for the specified device could not be found or is invalid. |
| **DIERR_CANCELLED** | The user canceled the operation. |
| **DIERR_BADINF** | The INF file for the device that the user selected could not be found or is invalid or damaged. |
| **S_FALSE** | DirectInput could not determine whether the operation completed successfully. |