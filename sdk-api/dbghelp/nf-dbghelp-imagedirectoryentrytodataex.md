# ImageDirectoryEntryToDataEx function

## Description

Locates a directory entry within the image header and returns the address of the data for the directory entry. This function returns the section header for the data located, if one exists.

## Parameters

### `Base` [in]

The base address of the image or data file.

### `MappedAsImage` [in]

If the flag is **TRUE**, the file is mapped by the system as an image. If this flag is **FALSE**, the file is mapped as a data file by the
[MapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffile) function.

### `DirectoryEntry` [in]

The directory entry to be located. The value must be one of the following values.

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

### `Size` [out]

A pointer to a variable that receives the size of the data for the directory entry that is located.

### `FoundHeader` [out, optional]

A pointer to an
[IMAGE_SECTION_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-image_section_header) structure that receives the data. If the section header does not exist, this parameter is **NULL**.

## Return value

If the function succeeds, the return value is a pointer to the data for the directory entry.

If the function fails, the return value is **NULL**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[IMAGE_SECTION_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-image_section_header)

[MapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffile)