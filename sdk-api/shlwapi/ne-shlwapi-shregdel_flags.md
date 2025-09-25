# SHREGDEL_FLAGS enumeration

## Description

Provides a set of values that indicate from which base key an item will be deleted.

## Constants

### `SHREGDEL_DEFAULT:0x00000000`

Deletes from **HKEY_CURRENT_USER**. If the specified item is not found under **HKEY_CURRENT_USER**, deletes from **HKEY_LOCAL_MACHINE**.

### `SHREGDEL_HKCU:0x00000001`

Enumerates from **HKEY_CURRENT_USER** only.

### `SHREGDEL_HKLM:0x00000010`

Enumerates under **HKEY_LOCAL_MACHINE** only.

### `SHREGDEL_BOTH:0x00000011`

Deletes from both **HKEY_CURRENT_USER** and **HKEY_LOCAL_MACHINE**.