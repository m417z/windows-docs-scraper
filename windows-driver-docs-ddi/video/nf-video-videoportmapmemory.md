# VideoPortMapMemory function

## Description

The **VideoPortMapMemory** function maps a range of bus-relative physical addresses of video memory into system space or into the virtual address space of a user-mode process. A video miniport driver calls **VideoPortMapMemory** when it handles IOCTL_VIDEO_MAP_VIDEO_MEMORY, IOCTL_VIDEO_SHARE_VIDEO_MEMORY, or IOCTL_VIDEO_QUERY_PUBLIC_ACCESS_RANGES.

## Parameters

### `HwDeviceExtension`

Pointer to the miniport driver's device extension.

### `PhysicalAddress`

The bus-relative base address of the range to map.

### `Length`

On input, specifies the number of bytes of video memory to map. On output, receives the size of the memory actually mapped, which might be rounded to a system-determined alignment boundary. (However, the miniport and display drivers cannot access any memory that is outside the range delimited by the input value at *Length*.)

### `InIoSpace`

Pointer to a variable that indicates the location of the range. The variable can be one of the following flags or an ORed, compatible combination of these flags.

| **Flag** | **Meaning** |
|:--|:--|
| VIDEO_MEMORY_SPACE_DENSE | Obsolete. |
| VIDEO_MEMORY_SPACE_IO | The address range is in I/O space, not in memory space. |
| VIDEO_MEMORY_SPACE_MEMORY | The address range is in memory space, not in I/O space. |
| VIDEO_MEMORY_SPACE_P6CACHE | The processor aggregates a sequence of write operations, sends them to a cache line, and later flushes the cache. This flag is meaningful only if VIDEO_MEMORY_SPACE_IO is not set.
Designates the video memory as write-combined (WC). For information about WC caching, see the [Write-Combining Memory in Video Miniport Drivers](https://learn.microsoft.com/previous-versions/windows/hardware/design/dn642116(v=vs.85)) website article. |
| VIDEO_MEMORY_SPACE_USER_MODE | The address range should be mapped into the virtual address space of a user-mode process, not into system space. This flag is meaningful only if VIDEO_MEMORY_SPACE_IO is not set. |

### `VirtualAddress`

Pointer to a variable that, on input, is either **NULL** or a handle to a user-mode process. If the input value is **NULL**, this routine maps the video memory into system space. Otherwise, this routine maps the video memory into the virtual address space of the user-mode process that is identified by the handle. On output, receives the base virtual address of the mapping.

## Return value

**VideoPortMapMemory** returns NO_ERROR if it successfully mapped the specified range; otherwise, it returns ERROR_INVALID_PARAMETER.

## Remarks

**VideoPortMapMemory** runs in kernel mode within the same context as the user-mode thread that initiated the call.

[VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase) and **VideoPortMapMemory** can both be called by the video miniport driver to map video memory into a virtual address space. If you call both of these functions to map the same physical addresses, or if you call one of the functions more than once to map the same physical addresses, you might have more than one virtual-address range that maps to the same physical-address range. In that case, you must set the VIDEO_MEMORY_SPACE_P6CACHE flag of the *InIoSpace* parameter to the same value in all of those calls.

Every universal memory architecture (UMA) display device uses a frame buffer that is located in main memory rather than on a PCI bus. In this case, do not call **VideoPortMapMemory** to map the frame buffer. To map a UMA frame buffer into system space, call [MmMapIoSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmapiospace). To map a UMA frame buffer into the virtual address space of a user-mode process, perform the following steps:

1. Call [ZwOpenSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwopensection) to get a handle to the operating system's physical-memory section object, which is named **\Device\PhysicalMemory**.
2. Call [ZwMapViewOfSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwmapviewofsection) to map a view of the frame buffer into the virtual address space of the current process.

The following example shows how to map a UMA frame buffer into the virtual address space of the current process.

```cpp
UNICODE_STRING    UnicodeString;          // Name of the section object
OBJECT_ATTRIBUTES ObjectAttributes;       // Description for the section object
HANDLE            hPhysicalMemoryHandle;  // Handle to the section object
PHYSICAL_ADDRESS  MappedLength;           // Length of the frame buffer

PHYSICAL_ADDRESS  MappedBase;             // Base physical address (CPU-relative)
                                          // of the frame buffer

// Allocate a variable to receive the base virtual address of the view.
// Set it to NULL for input to ZwMapViewOfSection, to specify that the memory
// manager (rather than the caller) should determine the base virtual address.
PVOID pViewBase = NULL;

RtlInitUnicodeString(&UnicodeString, L"\\Device\\PhysicalMemory");

InitializeObjectAttributes(
   &ObjectAttributes,
   &UnicodeString,
   OBJ_CASE_INSENSITIVE | OBJ_KERNEL_HANDLE,
   (HANDLE) NULL,
   (PSECURITY_DESCRIPTOR) NULL);

// Open a handle to the physical-memory section object.
ntStatus = ZwOpenSection(&hPhysicalMemoryHandle, SECTION_ALL_ACCESS, &ObjectAttributes);

if(NT_SUCCESS(ntStatus))
{
   ntStatus = ZwMapViewOfSection(
      hPhysicalMemoryHandle,
      NtCurrentProcess(),
      &pViewBase,
      0L,
      (ULONG_PTR)MappedLength.QuadPart,
      &MappedBase,
      (PULONG_PTR)(&(MappedLength.QuadPart)),
      ViewUnmap,
      0,
      PAGE_READWRITE | PAGE_WRITECOMBINE);

   if(NT_SUCCESS(ntStatus))
   {
      // pViewBase holds the base virtual address of the view.
   }

   // Close the handle to the physical-memory section object.
   ZwClose(hPhysicalMemoryHandle);
}
```

Miniport drivers should use **VideoPortMapMemory** to manage video adapters that allow the video [frame buffer](https://learn.microsoft.com/windows-hardware/drivers/) to be completely mapped at all times. That is, miniport drivers for adapters that are not restricted to using [banks](https://learn.microsoft.com/windows-hardware/drivers/) to map a slice at a time can use the more efficient **VideoPortMapMemory**.

## See also

[IOCTL_VIDEO_MAP_VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_map_video_memory)

[VIDEO_REQUEST_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_request_packet)

[VideoPortUnmapMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportunmapmemory)