# RAWINPUT structure

## Description

Contains the raw input from a device.

## Members

### `header`

Type: **[RAWINPUTHEADER](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawinputheader)**

The raw input data.

### `data`

### `data.mouse`

Type: **[RAWMOUSE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawmouse)**

If the data comes from a mouse, this is the raw input data.

### `data.keyboard`

Type: **[RAWKEYBOARD](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawkeyboard)**

If the data comes from a keyboard, this is the raw input data.

### `data.hid`

Type: **[RAWHID](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawhid)**

If the data comes from an HID, this is the raw input data.

## Remarks

The handle to this structure is passed in the *lParam* parameter of [WM_INPUT](https://learn.microsoft.com/windows/desktop/inputdev/wm-input).

To get detailed information -- such as the header and the content of the raw input -- call [GetRawInputData](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getrawinputdata).

To read the **RAWINPUT** in the message loop as a buffered read, call [GetRawInputBuffer](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getrawinputbuffer).

To get device specific information, call [GetRawInputDeviceInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getrawinputdeviceinfoa) with the *hDevice* from [RAWINPUTHEADER](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawinputheader).

Raw input is available only when the application calls [RegisterRawInputDevices](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerrawinputdevices) with valid device specifications.

## See also

**Conceptual**

[GetRawInputBuffer](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getrawinputbuffer)

[GetRawInputData](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getrawinputdata)

[RAWHID](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawhid)

[RAWINPUTHEADER](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawinputheader)

[RAWKEYBOARD](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawkeyboard)

[RAWMOUSE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawmouse)

[Raw Input](https://learn.microsoft.com/windows/desktop/inputdev/raw-input)

**Reference**