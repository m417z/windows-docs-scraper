# ASM_DISPLAY_FLAGS enumeration

## Description

The values of the **ASM_DISPLAY_FLAGS** enumeration are used by the [GetDisplayName](https://learn.microsoft.com/windows/desktop/api/winsxs/nf-winsxs-iassemblyname-getdisplayname) method to specify which portions of the assembly's full name to include in the string representation of the assembly name.

## Constants

### `ASM_DISPLAYF_VERSION:0x1`

Include the version number.

### `ASM_DISPLAYF_CULTURE:0x2`

Include the culture.

### `ASM_DISPLAYF_PUBLIC_KEY_TOKEN:0x4`

Include the public key token.

### `ASM_DISPLAYF_PUBLIC_KEY:0x8`

Include the public key.

### `ASM_DISPLAYF_CUSTOM:0x10`

Include the custom part of the assembly name.

### `ASM_DISPLAYF_PROCESSORARCHITECTURE:0x20`

Include the processor architecture.

### `ASM_DISPLAYF_LANGUAGEID:0x40`

Reserved.