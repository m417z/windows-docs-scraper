# IMAGE_SECTION_HEADER structure

## Description

Represents the image section header format.

## Members

### `Name`

An 8-byte, null-padded UTF-8 string. There is no terminating null character if the string is exactly eight characters long. For longer names, this member contains a forward slash (/) followed by an ASCII representation of a decimal number that is an offset into the string table. Executable images do not use a string table and do not support section names longer than eight characters.

### `Misc`

### `Misc.PhysicalAddress`

The file address.

### `Misc.VirtualSize`

The total size of the section when loaded into memory, in bytes. If this value is greater than the **SizeOfRawData** member, the section is filled with zeroes. This field is valid only for executable images and should be set to 0 for object files.

### `VirtualAddress`

The address of the first byte of the section when loaded into memory, relative to the image base. For object files, this is the address of the first byte before relocation is applied.

### `SizeOfRawData`

The size of the initialized data on disk, in bytes. This value must be a multiple of the **FileAlignment** member of the
[IMAGE_OPTIONAL_HEADER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-image_optional_header32) structure. If this value is less than the **VirtualSize** member, the remainder of the section is filled with zeroes. If the section contains only uninitialized data, the member is zero.

### `PointerToRawData`

A file pointer to the first page within the COFF file. This value must be a multiple of the **FileAlignment** member of the
[IMAGE_OPTIONAL_HEADER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-image_optional_header32) structure. If a section contains only uninitialized data, set this member is zero.

### `PointerToRelocations`

 A file pointer to the beginning of the relocation entries for the section. If there are no relocations, this value is zero.

### `PointerToLinenumbers`

A file pointer to the beginning of the line-number entries for the section. If there are no COFF line numbers, this value is zero.

### `NumberOfRelocations`

The number of relocation entries for the section. This value is zero for executable images.

### `NumberOfLinenumbers`

The number of line-number entries for the section.

### `Characteristics`

The characteristics of the image. The following values are defined.

| Flag | Meaning |
| --- | --- |
| 0x00000000 | Reserved. |
| 0x00000001 | Reserved. |
| 0x00000002 | Reserved. |
| 0x00000004 | Reserved. |
| **IMAGE_SCN_TYPE_NO_PAD**<br><br>0x00000008 | The section should not be padded to the next boundary. This flag is obsolete and is replaced by IMAGE_SCN_ALIGN_1BYTES. |
| 0x00000010 | Reserved. |
| **IMAGE_SCN_CNT_CODE**<br><br>0x00000020 | The section contains executable code. |
| **IMAGE_SCN_CNT_INITIALIZED_DATA**<br><br>0x00000040 | The section contains initialized data. |
| **IMAGE_SCN_CNT_UNINITIALIZED_DATA**<br><br>0x00000080 | The section contains uninitialized data. |
| **IMAGE_SCN_LNK_OTHER**<br><br>0x00000100 | Reserved. |
| **IMAGE_SCN_LNK_INFO**<br><br>0x00000200 | The section contains comments or other information. This is valid only for object files. |
| 0x00000400 | Reserved. |
| **IMAGE_SCN_LNK_REMOVE**<br><br>0x00000800 | The section will not become part of the image. This is valid only for object files. |
| **IMAGE_SCN_LNK_COMDAT**<br><br>0x00001000 | The section contains COMDAT data. This is valid only for object files. |
| 0x00002000 | Reserved. |
| **IMAGE_SCN_NO_DEFER_SPEC_EXC**<br><br>0x00004000 | Reset speculative exceptions handling bits in the TLB entries for this section. |
| **IMAGE_SCN_GPREL**<br><br>0x00008000 | The section contains data referenced through the global pointer. |
| 0x00010000 | Reserved. |
| **IMAGE_SCN_MEM_PURGEABLE**<br><br>0x00020000 | Reserved. |
| **IMAGE_SCN_MEM_LOCKED**<br><br>0x00040000 | Reserved. |
| **IMAGE_SCN_MEM_PRELOAD**<br><br>0x00080000 | Reserved. |
| **IMAGE_SCN_ALIGN_1BYTES**<br><br>0x00100000 | Align data on a 1-byte boundary. This is valid only for object files. |
| **IMAGE_SCN_ALIGN_2BYTES**<br><br>0x00200000 | Align data on a 2-byte boundary. This is valid only for object files. |
| **IMAGE_SCN_ALIGN_4BYTES**<br><br>0x00300000 | Align data on a 4-byte boundary. This is valid only for object files. |
| **IMAGE_SCN_ALIGN_8BYTES**<br><br>0x00400000 | Align data on a 8-byte boundary. This is valid only for object files. |
| **IMAGE_SCN_ALIGN_16BYTES**<br><br>0x00500000 | Align data on a 16-byte boundary. This is valid only for object files. |
| **IMAGE_SCN_ALIGN_32BYTES**<br><br>0x00600000 | Align data on a 32-byte boundary. This is valid only for object files. |
| **IMAGE_SCN_ALIGN_64BYTES**<br><br>0x00700000 | Align data on a 64-byte boundary. This is valid only for object files. |
| **IMAGE_SCN_ALIGN_128BYTES**<br><br>0x00800000 | Align data on a 128-byte boundary. This is valid only for object files. |
| **IMAGE_SCN_ALIGN_256BYTES**<br><br>0x00900000 | Align data on a 256-byte boundary. This is valid only for object files. |
| **IMAGE_SCN_ALIGN_512BYTES**<br><br>0x00A00000 | Align data on a 512-byte boundary. This is valid only for object files. |
| **IMAGE_SCN_ALIGN_1024BYTES**<br><br>0x00B00000 | Align data on a 1024-byte boundary. This is valid only for object files. |
| **IMAGE_SCN_ALIGN_2048BYTES**<br><br>0x00C00000 | Align data on a 2048-byte boundary. This is valid only for object files. |
| **IMAGE_SCN_ALIGN_4096BYTES**<br><br>0x00D00000 | Align data on a 4096-byte boundary. This is valid only for object files. |
| **IMAGE_SCN_ALIGN_8192BYTES**<br><br>0x00E00000 | Align data on a 8192-byte boundary. This is valid only for object files. |
| **IMAGE_SCN_LNK_NRELOC_OVFL**<br><br>0x01000000 | The section contains extended relocations. The count of relocations for the section exceeds the 16 bits that is reserved for it in the section header. If the **NumberOfRelocations** field in the section header is 0xffff, the actual relocation count is stored in the **VirtualAddress** field of the first relocation. It is an error if IMAGE_SCN_LNK_NRELOC_OVFL is set and there are fewer than 0xffff relocations in the section. |
| **IMAGE_SCN_MEM_DISCARDABLE**<br><br>0x02000000 | The section can be discarded as needed. |
| **IMAGE_SCN_MEM_NOT_CACHED**<br><br>0x04000000 | The section cannot be cached. |
| **IMAGE_SCN_MEM_NOT_PAGED**<br><br>0x08000000 | The section cannot be paged. |
| **IMAGE_SCN_MEM_SHARED**<br><br>0x10000000 | The section can be shared in memory. |
| **IMAGE_SCN_MEM_EXECUTE**<br><br>0x20000000 | The section can be executed as code. |
| **IMAGE_SCN_MEM_READ**<br><br>0x40000000 | The section can be read. |
| **IMAGE_SCN_MEM_WRITE**<br><br>0x80000000 | The section can be written to. |

## See also

[ImageDirectoryEntryToDataEx](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-imagedirectoryentrytodataex)

[ImageHlp Structures](https://learn.microsoft.com/windows/desktop/Debug/imagehlp-structures)

[ImageRvaToSection](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-imagervatosection)

[ImageRvaToVa](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-imagervatova)

[LOADED_IMAGE](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-loaded_image)