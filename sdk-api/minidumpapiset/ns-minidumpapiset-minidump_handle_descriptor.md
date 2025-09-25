# MINIDUMP_HANDLE_DESCRIPTOR structure

## Description

Contains the state of an individual system handle at the time the minidump was written.

## Members

### `Handle`

The operating system handle value.

### `TypeNameRva`

An RVA to a
[MINIDUMP_STRING](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_string) structure that specifies the object type of the handle. This member can be zero.

### `ObjectNameRva`

An RVA to a
[MINIDUMP_STRING](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_string) structure that specifies the object name of the handle. This member can be zero.

### `Attributes`

The meaning of this member depends on the handle type and the operating system.

### `GrantedAccess`

The meaning of this member depends on the handle type and the operating system.

### `HandleCount`

The meaning of this member depends on the handle type and the operating system.

### `PointerCount`

The meaning of this member depends on the handle type and the operating system.

## Remarks

The first descriptor in the handle data stream follows the header,
[MINIDUMP_HANDLE_DATA_STREAM](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_handle_data_stream).

## See also

[MINIDUMP_HANDLE_DATA_STREAM](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_handle_data_stream)

[MINIDUMP_STRING](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_string)