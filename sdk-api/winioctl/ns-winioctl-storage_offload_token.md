# STORAGE_OFFLOAD_TOKEN structure

## Description

Contains the token used to represent a portion of a file used in by offload read and write operations specified
by **DeviceDsmAction_OffloadRead** or **DeviceDsmAction_OffloadWrite**
actions for the
[IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_manage_data_set_attributes)
control code.

## Members

### `TokenType`

A 32-bit unsigned integer which defines the type of **Token**.

#### STORAGE_OFFLOAD_TOKEN_TYPE_WELL_KNOWN (0xFFFFFFFF)

The **Token** member uses a well-known format. The first two bytes of the
**Token** member are a 16-bit unsigned integer that describes the region.
The possible values are either **STORAGE_OFFLOAD_PATTERN_ZERO** or
**STORAGE_OFFLOAD_PATTERN_ZERO_WITH_PROTECTION_INFO**.
**STORAGE_OFFLOAD_PATTERN_ZERO** (0x0001) is a well-known token that indicates that the
region represented has all bits set to zero.
**STORAGE_OFFLOAD_PATTERN_ZERO_WITH_PROTECTION_INFO** is a well-known token that indicates
that the data in the region represented has all bits set to zero and the corresponding protection information
is valid.

#### 0x00000000–0xFFFFFFFE

The **Token** member uses a vendor-specific format.

### `Reserved`

Reserved.

### `TokenIdLength`

The length of the token data in **Token**.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.StorageOffloadZeroDataToken`

### `DUMMYUNIONNAME.StorageOffloadZeroDataToken.Reserved2`

Reserved.

### `DUMMYUNIONNAME.Token`

If the **TokenType** member is
**STORAGE_OFFLOAD_TOKEN_TYPE_WELL_KNOWN** then the first two bytes are a 16-bit unsigned
integer that describes the range. Otherwise this is a vendor-specific format.