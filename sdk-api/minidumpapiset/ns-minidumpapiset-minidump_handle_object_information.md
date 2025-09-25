# MINIDUMP_HANDLE_OBJECT_INFORMATION structure

## Description

Contains object-specific information for a handle.

## Members

### `NextInfoRva`

An RVA to a
**MINIDUMP_HANDLE_OBJECT_INFORMATION** structure that specifies additional object-specific information. This member is 0 if there are no more elements in the list.

### `InfoType`

The object information type. This member is one of the values from the [MINIDUMP_HANDLE_OBJECT_INFORMATION_TYPE](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ne-minidumpapiset-minidump_handle_object_information_type) enumeration.

### `SizeOfInfo`

The size of the information that follows this member, in bytes.

## See also

[MINIDUMP_HANDLE_DESCRIPTOR_2](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_handle_descriptor_2)