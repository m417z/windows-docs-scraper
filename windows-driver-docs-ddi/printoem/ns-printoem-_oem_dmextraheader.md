## Description

The **OEM_DMEXTRAHEADER** structure must be used to define the first members of a set of private [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure members.

## Members

### `dwSize`

Total size, in bytes, of the added private **DEVMODEW** structure members, including the bytes contained in the **OEM_DMEXTRAHEADER** structure.

### `dwSignature`

Unique signature value that the plug-in also returns when its [IPrintOemUI::GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-getinfo) method receives the OEMGI_GETSIGNATURE flag.

### `dwVersion`

Version number of the user interface plug-in that is defining the private **DEVMODEW** structure members. The version format is developer-defined.

## Remarks

For more information about adding **DEVMODEW** structure members, see [Providing DEVMODE Structure Additions](https://learn.microsoft.com/windows-hardware/drivers/print/providing-devmode-structure-additions).