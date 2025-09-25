# IMAGE_FILE_HEADER structure

## Description

Represents the COFF header format.

## Members

### `Machine`

The architecture type of the computer. An image file can only be run on the specified computer or a system
that emulates the specified computer. This member can be one of the following values.

For a complete list of valid Machine types and supported architectures, see the [PE Format](https://learn.microsoft.com/windows/win32/debug/pe-format#machine-types) documentation.

### `NumberOfSections`

The number of sections. This indicates the size of the section table, which immediately follows the
headers. Note that the Windows loader limits the number of sections to 96.

### `TimeDateStamp`

The low 32 bits of the time stamp of the image. This represents the date and time the image was created by
the linker. The value is represented in the number of seconds elapsed since midnight (00:00:00), January 1,
1970, Universal Coordinated Time, according to the system clock.

### `PointerToSymbolTable`

The offset of the symbol table, in bytes, or zero if no COFF symbol table exists.

### `NumberOfSymbols`

The number of symbols in the symbol table.

### `SizeOfOptionalHeader`

The size of the optional header, in bytes. This value should be 0 for object files.

### `Characteristics`

The characteristics of the image. This member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **IMAGE_FILE_RELOCS_STRIPPED**<br><br>0x0001 | Relocation information was stripped from the file. The file must be loaded at its preferred base address. If the base address is not available, the loader reports an error. |
| **IMAGE_FILE_EXECUTABLE_IMAGE**<br><br>0x0002 | The file is executable (there are no unresolved external references). |
| **IMAGE_FILE_LINE_NUMS_STRIPPED**<br><br>0x0004 | COFF line numbers were stripped from the file. |
| **IMAGE_FILE_LOCAL_SYMS_STRIPPED**<br><br>0x0008 | COFF symbol table entries were stripped from file. |
| **IMAGE_FILE_AGGRESIVE_WS_TRIM**<br><br>0x0010 | Aggressively trim the working set. This value is obsolete. |
| **IMAGE_FILE_LARGE_ADDRESS_AWARE**<br><br>0x0020 | The application can handle addresses larger than 2 GB. |
| **IMAGE_FILE_BYTES_REVERSED_LO**<br><br>0x0080 | The bytes of the word are reversed. This flag is obsolete. |
| **IMAGE_FILE_32BIT_MACHINE**<br><br>0x0100 | The computer supports 32-bit words. |
| **IMAGE_FILE_DEBUG_STRIPPED**<br><br>0x0200 | Debugging information was removed and stored separately in another file. |
| **IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP**<br><br>0x0400 | If the image is on removable media, copy it to and run it from the swap file. |
| **IMAGE_FILE_NET_RUN_FROM_SWAP**<br><br>0x0800 | If the image is on the network, copy it to and run it from the swap file. |
| **IMAGE_FILE_SYSTEM**<br><br>0x1000 | The image is a system file. |
| **IMAGE_FILE_DLL**<br><br>0x2000 | The image is a DLL file. While it is an executable file, it cannot be run directly. |
| **IMAGE_FILE_UP_SYSTEM_ONLY**<br><br>0x4000 | The file should be run only on a uniprocessor computer. |
| **IMAGE_FILE_BYTES_REVERSED_HI**<br><br>0x8000 | The bytes of the word are reversed. This flag is obsolete. |

## See also

[IMAGE_NT_HEADERS](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-image_nt_headers32)

[ImageHlp Structures](https://learn.microsoft.com/windows/desktop/Debug/imagehlp-structures)