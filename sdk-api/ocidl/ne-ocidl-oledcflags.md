# OLEDCFLAGS enumeration

## Description

Specifies additional information to the container about the device context that the object has requested.

## Constants

### `OLEDC_NODRAW:0x1`

Indicates that the object will not use the returned **HDC** for drawing but merely to get information about the display device. In this case, the container can simply pass the window's device context without further processing.

### `OLEDC_PAINTBKGND:0x2`

Requests that the container paint the background behind the object before returning the device context. Objects should use this flag when requesting a device context to paint a transparent area.

### `OLEDC_OFFSCREEN:0x4`

Indicates that the object prefers to draw into an offscreen device context that should then be copied to the screen. The container can honor this request or not. If this bit is cleared, the container must return an on-screen device context allowing the object to perform direct screen operations such as showing a selection through an XOR operation. An object can specify this value when the drawing operation generates a lot of screen flicker.

## See also

[IOleInPlaceSiteWindowless::GetDC](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleinplacesitewindowless-getdc)