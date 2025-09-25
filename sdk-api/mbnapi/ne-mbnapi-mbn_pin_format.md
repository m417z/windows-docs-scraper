# MBN_PIN_FORMAT enumeration

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

The **MBN_PIN_FORMAT** enumerated type indicates whether a PIN is numeric or alphanumeric.

## Constants

### `MBN_PIN_FORMAT_NONE:0`

Indicates that the PIN format is not known.

### `MBN_PIN_FORMAT_NUMERIC`

Indicates that the PIN is in numeric format. The only allowed characters are 0-9.

### `MBN_PIN_FORMAT_ALPHANUMERIC`

Indicates that the PIN is in alphanumeric format. Allowed characters are a-z, A-Z, 0-9, *, and #.