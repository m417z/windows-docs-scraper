# IMAGE_DEBUG_INFORMATION structure

## Description

Contains debugging information.

**Note** This structure is used by the
[MapDebugInformation](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-mapdebuginformation) and
[UnmapDebugInformation](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-unmapdebuginformation) functions, which are
provided only for backward compatibility.

## Members

### `List`

A linked list of **LIST_ENTRY** structures.

### `ReservedSize`

The size of the memory allocated for the
**IMAGE_DEBUG_INFORMATION** structure and all
debugging information, in bytes.

### `ReservedMappedBase`

The base address of the image.

### `ReservedMachine`

The computer type. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **IMAGE_FILE_MACHINE_I386**<br><br>0x014c | Intel (32-bit) |
| **IMAGE_FILE_MACHINE_IA64**<br><br>0x0200 | Intel Itanium |
| **IMAGE_FILE_MACHINE_AMD64**<br><br>0x8664 | x64 (AMD64 or EM64T) |

### `ReservedCharacteristics`

The characteristics of the image. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **IMAGE_FILE_RELOCS_STRIPPED**<br><br>0x0001 | Relocation information is stripped from the file. |
| **IMAGE_FILE_EXECUTABLE_IMAGE**<br><br>0x0002 | The file is executable (there are no unresolved external references). |
| **IMAGE_FILE_LINE_NUMS_STRIPPED**<br><br>0x0004 | Line numbers are stripped from the file. |
| **IMAGE_FILE_LOCAL_SYMS_STRIPPED**<br><br>0x0008 | Local symbols are stripped from file. |
| **IMAGE_FILE_AGGRESIVE_WS_TRIM**<br><br>0x0010 | Aggressively trim the working set. |
| **IMAGE_FILE_LARGE_ADDRESS_AWARE**<br><br>0x0020 | The application can handle addresses larger than 2 GB. |
| **IMAGE_FILE_BYTES_REVERSED_LO**<br><br>0x0080 | Bytes of the word are reversed. |
| **IMAGE_FILE_32BIT_MACHINE**<br><br>0x0100 | Computer supports 32-bit words. |
| **IMAGE_FILE_DEBUG_STRIPPED**<br><br>0x0200 | Debugging information is stored separately in a .dbg file. |
| **IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP**<br><br>0x0400 | If the image is on removable media, copy and run from the swap file. |
| **IMAGE_FILE_NET_RUN_FROM_SWAP**<br><br>0x0800 | If the image is on the network, copy and run from the swap file. |
| **IMAGE_FILE_SYSTEM**<br><br>0x1000 | System file. |
| **IMAGE_FILE_DLL**<br><br>0x2000 | DLL file. |
| **IMAGE_FILE_UP_SYSTEM_ONLY**<br><br>0x4000 | File should be run only on a uniprocessor computer. |
| **IMAGE_FILE_BYTES_REVERSED_HI**<br><br>0x8000 | Bytes of the word are reversed. |

### `ReservedCheckSum`

The checksum of the image.

### `ImageBase`

The requested base address of the image.

### `SizeOfImage`

The size of the image, in bytes.

### `ReservedNumberOfSections`

The number of COFF section headers.

### `ReservedSections`

A pointer to the first COFF section header. For more information, see
[IMAGE_SECTION_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-image_section_header).

### `ReservedExportedNamesSize`

The size of the **ExportedNames** member, in bytes.

### `ReservedExportedNames`

A pointer to a series of null-terminated strings that name all the functions exported from the image.

### `ReservedNumberOfFunctionTableEntries`

The number of entries contained in the **FunctionTableEntries** member.

### `ReservedFunctionTableEntries`

A pointer to the first function table entry. For more information, see
[IMAGE_FUNCTION_ENTRY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-image_function_entry).

### `ReservedLowestFunctionStartingAddress`

The lowest function table starting address.

### `ReservedHighestFunctionEndingAddress`

The highest function table ending address.

### `ReservedNumberOfFpoTableEntries`

The number of entries contained in the **FpoTableEntries** member.

### `ReservedFpoTableEntries`

A pointer to the first FPO entry. For more information, see
[FPO_DATA](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-fpo_data).

### `SizeOfCoffSymbols`

The size of the COFF symbol table, in bytes.

### `CoffSymbols`

A pointer to the COFF symbol table.

### `ReservedSizeOfCodeViewSymbols`

The size of the CodeView symbol table, in bytes.

### `ReservedCodeViewSymbols`

A pointer to the beginning of the CodeView symbol table.

### `ImageFilePath`

The relative path to the image file name.

### `ImageFileName`

The image file name.

### `ReservedDebugFilePath`

The full path to the symbol file.

### `ReservedTimeDateStamp`

The timestamp of the image. This represents the date and time the image was created by the linker.

### `ReservedRomImage`

This value is **TRUE** if the image is a ROM image.

### `ReservedDebugDirectory`

A pointer to the first debug directory. For more information, see
[IMAGE_DEBUG_DIRECTORY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-image_debug_directory).

### `ReservedNumberOfDebugDirectories`

The number of entries contained in the **DebugDirectory** member.

### `ReservedOriginalFunctionTableBaseAddress`

The original function table base address.

### `Reserved`

This member is reserved for use by the operating system.

## Remarks

The **LIST_ENTRY** structure is defined as follows:

```cpp
typedef struct _LIST_ENTRY {
   struct _LIST_ENTRY *Flink;
   struct _LIST_ENTRY *Blink;
} LIST_ENTRY, *PLIST_ENTRY, *RESTRICTED_POINTER PRLIST_ENTRY;
```

## See also

[FPO_DATA](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-fpo_data)

[IMAGE_COFF_SYMBOLS_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-image_coff_symbols_header)

[IMAGE_DEBUG_DIRECTORY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-image_debug_directory)

[IMAGE_FUNCTION_ENTRY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-image_function_entry)

[IMAGE_SECTION_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-image_section_header)

[MapDebugInformation](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-mapdebuginformation)

[UnmapDebugInformation](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-unmapdebuginformation)