## Description

The **SECTION_OBJECT_POINTERS** structure, allocated by a file system or a redirector driver, is used by the memory manager and cache manager to store file-mapping and cache-related information for a file stream.

## Members

### `DataSectionObject`

Opaque pointer to a data section object (that is, a **CONTROL_AREA** structure) that is used to track state information for a data file stream. Memory manager sets this member when the operating system first caches the data stream. A **NULL** value indicates that the data stream is currently not in memory; this value, however, can change at any time.

### `SharedCacheMap`

Opaque pointer to a cache map object (that is, a **SHARED_CACHE_MAP** structure) that is used to track views that are mapped to the data file stream. Cache manager sets this member when the operating system first caches the stream. A **NULL** value indicates that the data stream is currently not cached; this value, however, can change at any time.

### `ImageSectionObject`

Opaque pointer to an image section object (that is, a **CONTROL_AREA** structure) that is used to track state information for an executable file stream. Memory manager sets this member whenever an executable image section is created for the stream. A **NULL** value indicates that the executable image is currently not in memory; this value, however, can change at any time.

## Remarks

The **SECTION_OBJECT_POINTERS** structure links a file object to a file stream's section object. That is, through its members, the **SECTION_OBJECT_POINTERS** structure connects a particular file object to virtual memory control structures that keep track of the stream's contents when they are in memory, and allow the operating system to fetch those contents when they are not.

There is a one-to-one relationship between a **SECTION_OBJECT_POINTERS** structure and a file stream. Multiple file objects can be associated with a particular file stream, each representing an open instance of the stream. However, only one **SECTION_OBJECT_POINTERS** structure can be associated with a given stream. If there are multiple file objects for a stream, the **SectionObjectPointer** member for all file objects must point to the same **SECTION_OBJECT_POINTERS** structure (that is associated with the stream).

For the first file stream open request, the file system or the redirector driver must:

1. Allocate a **SECTION_OBJECT_POINTERS** structure from a nonpaged pool.

1. Initialize all members of the allocated **SECTION_OBJECT_POINTERS** structure to **NULL**.

1. Set the **SectionObjectPointer** member of the associate file object to point to the initialized **SECTION_OBJECT_POINTERS** structure.

For subsequent open requests to the same file stream, the file system or the redirector driver must set the **SectionObjectPointer** member of the associated file object to point to the previously allocated **SECTION_OBJECT_POINTERS** structure for the file stream.

> [!WARNING]
> File system filter drivers must treat the members of the **SECTION_OBJECT_POINTERS** structure as opaque because the underlying file system is responsible for the synchronization of the members and, therefore, could change their values at any time.

A file is composed of one or more streams, depending on the file system. For more information, see [File Streams, Stream Contexts, and Per-Stream Contexts](https://learn.microsoft.com/windows-hardware/drivers/ifs/file-streams--stream-contexts--and-per-stream-contexts).

## See also

[CcInitializeCacheMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccinitializecachemap)

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object)

[FOBX](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-fobx-structure)

[FSRTL_ADVANCED_FCB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsrtl_advanced_fcb_header)

[IoGetDeviceObjectPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdeviceobjectpointer)

[MmFlushImageSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-mmflushimagesection)

[ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject)