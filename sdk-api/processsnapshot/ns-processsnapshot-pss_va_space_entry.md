# PSS_VA_SPACE_ENTRY structure

## Description

Holds the [MEMORY_BASIC_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-memory_basic_information) returned by [PssWalkSnapshot](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-psswalksnapshot) for a virtual address (VA) region.

## Members

### `BaseAddress`

Information about the VA region. For more information, see [MEMORY_BASIC_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-memory_basic_information).

### `AllocationBase`

Information about the VA region. For more information, see [MEMORY_BASIC_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-memory_basic_information).

### `AllocationProtect`

Information about the VA region. For more information, see [MEMORY_BASIC_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-memory_basic_information).

### `RegionSize`

Information about the VA region. For more information, see [MEMORY_BASIC_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-memory_basic_information).

### `State`

Information about the VA region. For more information, see [MEMORY_BASIC_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-memory_basic_information).

### `Protect`

Information about the VA region. For more information, see [MEMORY_BASIC_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-memory_basic_information).

### `Type`

Information about the VA region. For more information, see [MEMORY_BASIC_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-memory_basic_information).

### `TimeDateStamp`

If section information was captured and the region is an executable image (**MEM_IMAGE**), this is the **TimeDateStamp** value from the Portable Executable (PE) header which describes the image. It is the low 32 bits of the number of seconds since 00:00 January 1, 1970 (a C run-time time_t value), that indicates when the file was created.

### `SizeOfImage`

If section information was captured and the region is an executable image (**MEM_IMAGE**), this is the **SizeOfImage** value from the Portable Executable (PE) header which describes the image. It is the size (in bytes) of the image, including all headers, as the image is loaded in memory.

### `ImageBase`

If section information was captured and the region is an executable image (**MEM_IMAGE**), this is the **ImageBase** value from the Portable Executable (PE) header which describes the image. It is the preferred address of the first byte of the image when loaded into memory.

### `CheckSum`

If section information was captured and the region is an executable image (**MEM_IMAGE**), this is the **CheckSum** value from the Portable Executable (PE) header which describes the image. It is the image file checksum.

### `MappedFileNameLength`

The length of the mapped file name buffer, in bytes.

### `MappedFileName`

If section information was captured, this is the file path backing the section (if any). The path may be in NT namespace. The string may not be terminated by a **NULL** character. The pointer is valid for the lifetime of the walk marker passed to [PssWalkSnapshot](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-psswalksnapshot).

## Remarks

[PssWalkSnapshot](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-psswalksnapshot) returns a **PSS_VA_SPACE_ENTRY** structure when the [PSS_WALK_INFORMATION_CLASS](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/ne-processsnapshot-pss_walk_information_class) member that the caller provides it is **PSS_WALK_VA_SPACE**.

## See also

[Process Snapshotting](https://learn.microsoft.com/previous-versions/windows/desktop/proc_snap/process-snapshotting-portal)