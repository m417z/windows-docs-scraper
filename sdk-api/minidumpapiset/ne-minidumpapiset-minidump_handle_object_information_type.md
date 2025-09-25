# MINIDUMP_HANDLE_OBJECT_INFORMATION_TYPE enumeration

## Description

Identifies the type of object-specific information.

## Constants

### `MiniHandleObjectInformationNone`

There is no object-specific information for this handle type.

### `MiniThreadInformation1`

The information is specific to thread objects.

### `MiniMutantInformation1`

The information is specific to mutant objects.

### `MiniMutantInformation2`

The information is specific to mutant objects.

### `MiniProcessInformation1`

The information is specific to process objects.

### `MiniProcessInformation2`

The information is specific to process objects.

### `MiniEventInformation1`

### `MiniSectionInformation1`

### `MiniSemaphoreInformation1`

### `MiniHandleObjectInformationTypeMax`

## Remarks

The information represented by each of these values can vary by operating system and procesor architecture. Per-handle object-specific information is automatically gathered when minidump type is MiniDumpWithHandleData. For more information, see [MINIDUMP_TYPE](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ne-minidumpapiset-minidump_type).

## See also

[MINIDUMP_HANDLE_OBJECT_INFORMATION](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_handle_object_information)