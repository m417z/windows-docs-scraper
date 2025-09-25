# MINIDUMP_HANDLE_DESCRIPTOR_2 structure

## Description

Describes the state of an individual system handle at the time the minidump was written.

## Members

### `Handle`

The operating system handle value.

### `TypeNameRva`

An RVA to a
[MINIDUMP_STRING](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_string) structure that specifies the object type of the handle. This member can be zero.

### `ObjectNameRva`

An RVA to a
[MINIDUMP_STRING](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_string) structure that specifies the object name of the handle. This member can be 0.

### `Attributes`

The meaning of this member depends on the handle type and the operating system.

### `GrantedAccess`

The meaning of this member depends on the handle type and the operating system.

### `HandleCount`

The meaning of this member depends on the handle type and the operating system.

### `PointerCount`

The meaning of this member depends on the handle type and the operating system.

### `ObjectInfoRva`

An RVA to a
[MINIDUMP_HANDLE_OBJECT_INFORMATION](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_handle_object_information) structure that specifies object-specific information. This member can be 0 if there is no extra information.

### `Reserved0`

Reserved for future use; must be zero.

## Remarks

The first descriptor in the handle data stream follows the header,
[MINIDUMP_HANDLE_DATA_STREAM](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_handle_data_stream).

## See also

[MINIDUMP_HANDLE_DATA_STREAM](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_handle_data_stream)

[MINIDUMP_HANDLE_OBJECT_INFORMATION](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_handle_object_information)

[MINIDUMP_STRING](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_string)