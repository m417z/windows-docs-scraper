# LOADED_IMAGE structure

## Description

Contains information about the loaded image.

## Members

### `ModuleName`

The file name of the mapped file.

### `hFile`

A handle to the mapped file.

### `MappedAddress`

The base address of the mapped file.

### `FileHeader`

A pointer to an
[IMAGE_NT_HEADERS](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-image_nt_headers32) structure.

### `LastRvaSection`

A pointer to an
[IMAGE_SECTION_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-image_section_header) structure.

### `NumberOfSections`

The number of COFF section headers.

### `Sections`

A pointer to an
[IMAGE_SECTION_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-image_section_header) structure.

### `Characteristics`

The image characteristics value. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **IMAGE_FILE_RELOCS_STRIPPED**<br><br>0x0001 | Relocation information is stripped from the file. |
| **IMAGE_FILE_EXECUTABLE_IMAGE**<br><br>0x0002 | The file is executable (there are no unresolved external references). |
| **IMAGE_FILE_LINE_NUMS_STRIPPED**<br><br>0x0004 | Line numbers are stripped from the file. |
| **IMAGE_FILE_LOCAL_SYMS_STRIPPED**<br><br>0x0008 | Local symbols are stripped from file. |
| **IMAGE_FILE_AGGRESIVE_WS_TRIM**<br><br>0x0010 | Aggressively trim the working set. |
| **IMAGE_FILE_LARGE_ADDRESS_AWARE**<br><br>0x0020 | The application can handle addresses larger than 2 GB. |
| **IMAGE_FILE_BYTES_REVERSED_LO**<br><br>0x0080 | Bytes of word are reversed. |
| **IMAGE_FILE_32BIT_MACHINE**<br><br>0x0100 | Computer supports 32-bit words. |
| **IMAGE_FILE_DEBUG_STRIPPED**<br><br>0x0200 | Debugging information is stored separately in a .dbg file. |
| **IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP**<br><br>0x0400 | If the image is on removable media, copy and run from the swap file. |
| **IMAGE_FILE_NET_RUN_FROM_SWAP**<br><br>0x0800 | If the image is on the network, copy and run from the swap file. |
| **IMAGE_FILE_SYSTEM**<br><br>0x1000 | System file. |
| **IMAGE_FILE_DLL**<br><br>0x2000 | DLL file. |
| **IMAGE_FILE_UP_SYSTEM_ONLY**<br><br>0x4000 | File should be run only on a uniprocessor computer. |
| **IMAGE_FILE_BYTES_REVERSED_HI**<br><br>0x8000 | Bytes of the word are reversed. |

### `fSystemImage`

If the image is a kernel mode executable image, this value is **TRUE**.

### `fDOSImage`

If the image is a 16-bit executable image, this value is **TRUE**.

### `fReadOnly`

If the image is read-only, this value is **TRUE**.

**Prior to Windows Vista:** This member is not included in the structure.

### `Version`

The version string.

**Prior to Windows Vista:** This member is not included in the structure.

### `Links`

The list of loaded images.

### `SizeOfImage`

The size of the image, in bytes.

## Remarks

The **LIST_ENTRY** structure is defined as follows:

```cpp
typedef struct _LIST_ENTRY {
   struct _LIST_ENTRY *Flink;
   struct _LIST_ENTRY *Blink;
} LIST_ENTRY, *PLIST_ENTRY, *RESTRICTED_POINTER PRLIST_ENTRY;
```

## See also

[IMAGE_NT_HEADERS](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-image_nt_headers32)

[IMAGE_SECTION_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-image_section_header)

[ImageLoad](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-imageload)

[MapAndLoad](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-mapandload)