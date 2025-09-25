# SHREGENUM_FLAGS enumeration

## Description

Provides a set of values that indicate the base key that will be used for an enumeration.

## Constants

### `SHREGENUM_DEFAULT:0x00000000`

Enumerates under **HKEY_CURRENT_USER**, or, if the specified item is not found in **HKEY_CURRENT_USER**, enumerates under **HKEY_LOCAL_MACHINE**.

### `SHREGENUM_HKCU:0x00000001`

Enumerates under **HKEY_CURRENT_USER** only.

### `SHREGENUM_HKLM:0x00000010`

Enumerates under **HKEY_LOCAL_MACHINE** only.

### `SHREGENUM_BOTH:0x00000011`

Not used.