# IMAGE_OPTIONAL_HEADER32 structure

## Description

Represents the optional header format.

## Members

### `Magic`

The state of the image file. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **IMAGE_NT_OPTIONAL_HDR_MAGIC** | The file is an executable image. This value is defined as **IMAGE_NT_OPTIONAL_HDR32_MAGIC** in a 32-bit application and as **IMAGE_NT_OPTIONAL_HDR64_MAGIC** in a 64-bit application. |
| **IMAGE_NT_OPTIONAL_HDR32_MAGIC**<br><br>0x10b | The file is an executable image. |
| **IMAGE_NT_OPTIONAL_HDR64_MAGIC**<br><br>0x20b | The file is an executable image. |
| **IMAGE_ROM_OPTIONAL_HDR_MAGIC**<br><br>0x107 | The file is a ROM image. |

### `MajorLinkerVersion`

The major version number of the linker.

### `MinorLinkerVersion`

The minor version number of the linker.

### `SizeOfCode`

The size of the code section, in bytes, or the sum of all such sections if there are multiple code
sections.

### `SizeOfInitializedData`

The size of the initialized data section, in bytes, or the sum of all such sections if there are multiple
initialized data sections.

### `SizeOfUninitializedData`

The size of the uninitialized data section, in bytes, or the sum of all such sections if there are multiple
uninitialized data sections.

### `AddressOfEntryPoint`

A pointer to the entry point function, relative to the image base address. For executable files, this is
the starting address. For device drivers, this is the address of the initialization function. The entry point
function is optional for DLLs. When no entry point is present, this member is zero.

### `BaseOfCode`

A pointer to the beginning of the code section, relative to the image base.

### `BaseOfData`

A pointer to the beginning of the data section, relative to the image base.

### `ImageBase`

The preferred address of the first byte of the image when it is loaded in memory. This value is a multiple
of 64K bytes. The default value for DLLs is 0x10000000. The default value for applications is 0x00400000, except
on Windows CE where it is 0x00010000.

### `SectionAlignment`

The alignment of sections loaded in memory, in bytes. This value must be greater than or equal to the
**FileAlignment** member. The default value is the page size for the system.

### `FileAlignment`

The alignment of the raw data of sections in the image file, in bytes. The value should be a power of 2
between 512 and 64K (inclusive). The default is 512. If the **SectionAlignment** member
is less than the system page size, this member must be the same as
**SectionAlignment**.

### `MajorOperatingSystemVersion`

The major version number of the required operating system.

### `MinorOperatingSystemVersion`

The minor version number of the required operating system.

### `MajorImageVersion`

The major version number of the image.

### `MinorImageVersion`

The minor version number of the image.

### `MajorSubsystemVersion`

The major version number of the subsystem.

### `MinorSubsystemVersion`

The minor version number of the subsystem.

### `Win32VersionValue`

This member is reserved and must be 0.

### `SizeOfImage`

The size of the image, in bytes, including all headers. Must be a multiple of
**SectionAlignment**.

### `SizeOfHeaders`

The combined size of the following items, rounded to a multiple of the value specified in the
**FileAlignment** member.

* **e_lfanew** member of **IMAGE_DOS_HEADER**
* 4 byte signature
* size of [IMAGE_FILE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-image_file_header)
* size of optional header
* size of all section headers

### `CheckSum`

The image file checksum. The following files are validated at load time: all drivers, any DLL loaded at
boot time, and any DLL loaded into a critical system process.

### `Subsystem`

The subsystem required to run this image. The following values are defined.

| Value | Meaning |
| --- | --- |
| **IMAGE_SUBSYSTEM_UNKNOWN**<br><br>0 | Unknown subsystem. |
| **IMAGE_SUBSYSTEM_NATIVE**<br><br>1 | No subsystem required (device drivers and native system processes). |
| **IMAGE_SUBSYSTEM_WINDOWS_GUI**<br><br>2 | Windows graphical user interface (GUI) subsystem. |
| **IMAGE_SUBSYSTEM_WINDOWS_CUI**<br><br>3 | Windows character-mode user interface (CUI) subsystem. |
| **IMAGE_SUBSYSTEM_OS2_CUI**<br><br>5 | OS/2 CUI subsystem. |
| **IMAGE_SUBSYSTEM_POSIX_CUI**<br><br>7 | POSIX CUI subsystem. |
| **IMAGE_SUBSYSTEM_WINDOWS_CE_GUI**<br><br>9 | Windows CE system. |
| **IMAGE_SUBSYSTEM_EFI_APPLICATION**<br><br>10 | Extensible Firmware Interface (EFI) application. |
| **IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER**<br><br>11 | EFI driver with boot services. |
| **IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER**<br><br>12 | EFI driver with run-time services. |
| **IMAGE_SUBSYSTEM_EFI_ROM**<br><br>13 | EFI ROM image. |
| **IMAGE_SUBSYSTEM_XBOX**<br><br>14 | Xbox system. |
| **IMAGE_SUBSYSTEM_WINDOWS_BOOT_APPLICATION**<br><br>16 | Boot application. |

### `DllCharacteristics`

The DLL characteristics of the image. The following values are defined.

| Value | Meaning |
| --- | --- |
| 0x0001 | Reserved. |
| 0x0002 | Reserved. |
| 0x0004 | Reserved. |
| 0x0008 | Reserved. |
| **IMAGE_DLL_CHARACTERISTICS_HIGH_ENTROPY_VA**<br><br>0x0020 | ASLR with 64 bit address space. |
| **IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE**<br><br>0x0040 | The DLL can be relocated at load time. |
| **IMAGE_DLLCHARACTERISTICS_FORCE_INTEGRITY**<br><br>0x0080 | Code integrity checks are forced. If you set this flag and a section contains only uninitialized data, set the **PointerToRawData** member of [IMAGE_SECTION_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-image_section_header) for that section to zero; otherwise, the image will fail to load because the digital signature cannot be verified. |
| **IMAGE_DLLCHARACTERISTICS_NX_COMPAT**<br><br>0x0100 | The image is compatible with data execution prevention (DEP). |
| **IMAGE_DLLCHARACTERISTICS_NO_ISOLATION**<br><br>0x0200 | The image is isolation aware, but should not be isolated. |
| **IMAGE_DLLCHARACTERISTICS_NO_SEH**<br><br>0x0400 | The image does not use structured exception handling (SEH). No handlers can be called in this image. |
| **IMAGE_DLLCHARACTERISTICS_NO_BIND**<br><br>0x0800 | Do not bind the image. |
| **IMAGE_DLL_CHARACTERISTICS_APPCONTAINER**<br><br>0x1000 | Image should execute in an AppContainer. |
| **IMAGE_DLLCHARACTERISTICS_WDM_DRIVER**<br><br>0x2000 | A WDM driver. |
| **IMAGE_DLL_CHARACTERISTICS_GUARD_CF**<br><br>0x4000 | Image supports Control Flow Guard. |
| **IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE**<br><br>0x8000 | The image is terminal server aware. |

### `SizeOfStackReserve`

The number of bytes to reserve for the stack. Only the memory specified by the
**SizeOfStackCommit** member is committed at load time; the rest is made available one
page at a time until this reserve size is reached.

### `SizeOfStackCommit`

The number of bytes to commit for the stack.

### `SizeOfHeapReserve`

The number of bytes to reserve for the local heap. Only the memory specified by the
**SizeOfHeapCommit** member is committed at load time; the rest is made available one
page at a time until this reserve size is reached.

### `SizeOfHeapCommit`

The number of bytes to commit for the local heap.

### `LoaderFlags`

This member is obsolete.

### `NumberOfRvaAndSizes`

The number of directory entries in the remainder of the optional header. Each entry describes a location
and size.

### `DataDirectory`

A pointer to the first
[IMAGE_DATA_DIRECTORY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-image_data_directory) structure in the data
directory.

The index number of the desired directory entry. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **IMAGE_DIRECTORY_ENTRY_ARCHITECTURE**<br><br>7 | Architecture-specific data |
| **IMAGE_DIRECTORY_ENTRY_BASERELOC**<br><br>5 | Base relocation table |
| **IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT**<br><br>11 | Bound import directory |
| **IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR**<br><br>14 | COM descriptor table |
| **IMAGE_DIRECTORY_ENTRY_DEBUG**<br><br>6 | Debug directory |
| **IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT**<br><br>13 | Delay import table |
| **IMAGE_DIRECTORY_ENTRY_EXCEPTION**<br><br>3 | Exception directory |
| **IMAGE_DIRECTORY_ENTRY_EXPORT**<br><br>0 | Export directory |
| **IMAGE_DIRECTORY_ENTRY_GLOBALPTR**<br><br>8 | The relative virtual address of global pointer |
| **IMAGE_DIRECTORY_ENTRY_IAT**<br><br>12 | Import address table |
| **IMAGE_DIRECTORY_ENTRY_IMPORT**<br><br>1 | Import directory |
| **IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG**<br><br>10 | Load configuration directory |
| **IMAGE_DIRECTORY_ENTRY_RESOURCE**<br><br>2 | Resource directory |
| **IMAGE_DIRECTORY_ENTRY_SECURITY**<br><br>4 | Security directory |
| **IMAGE_DIRECTORY_ENTRY_TLS**<br><br>9 | Thread local storage directory |

## Remarks

The number of directories is not fixed. Check the **NumberOfRvaAndSizes** member before
looking for a specific directory.

The actual structure in WinNT.h is named **IMAGE_OPTIONAL_HEADER32**
and **IMAGE_OPTIONAL_HEADER** is defined as
**IMAGE_OPTIONAL_HEADER32**. However, if **_WIN64** is
defined, then **IMAGE_OPTIONAL_HEADER** is defined as
**IMAGE_OPTIONAL_HEADER64**.

```cpp
typedef struct _IMAGE_OPTIONAL_HEADER64 {
 WORD        Magic;
 BYTE        MajorLinkerVersion;
 BYTE        MinorLinkerVersion;
 DWORD       SizeOfCode;
 DWORD       SizeOfInitializedData;
 DWORD       SizeOfUninitializedData;
 DWORD       AddressOfEntryPoint;
 DWORD       BaseOfCode;
 ULONGLONG   ImageBase;
 DWORD       SectionAlignment;
 DWORD       FileAlignment;
 WORD        MajorOperatingSystemVersion;
 WORD        MinorOperatingSystemVersion;
 WORD        MajorImageVersion;
 WORD        MinorImageVersion;
 WORD        MajorSubsystemVersion;
 WORD        MinorSubsystemVersion;
 DWORD       Win32VersionValue;
 DWORD       SizeOfImage;
 DWORD       SizeOfHeaders;
 DWORD       CheckSum;
 WORD        Subsystem;
 WORD        DllCharacteristics;
 ULONGLONG   SizeOfStackReserve;
 ULONGLONG   SizeOfStackCommit;
 ULONGLONG   SizeOfHeapReserve;
 ULONGLONG   SizeOfHeapCommit;
 DWORD       LoaderFlags;
 DWORD       NumberOfRvaAndSizes;
 IMAGE_DATA_DIRECTORY DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
} IMAGE_OPTIONAL_HEADER64, *PIMAGE_OPTIONAL_HEADER64;
```

## See also

[IMAGE_DATA_DIRECTORY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-image_data_directory)

[ImageHlp Structures](https://learn.microsoft.com/windows/desktop/Debug/imagehlp-structures)