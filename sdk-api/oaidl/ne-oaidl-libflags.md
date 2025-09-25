# LIBFLAGS enumeration

## Description

Defines flags that apply to type libraries.

## Constants

### `LIBFLAG_FRESTRICTED:0x1`

The type library is restricted, and should not be displayed to users.

### `LIBFLAG_FCONTROL:0x2`

The type library describes controls, and should not be displayed in type browsers intended for nonvisual objects.

### `LIBFLAG_FHIDDEN:0x4`

The type library should not be displayed to users, although its use is not restricted. Should be used by controls. Hosts should create a new type library that wraps the control with extended properties.

### `LIBFLAG_FHASDISKIMAGE:0x8`

The type library has a disk image.