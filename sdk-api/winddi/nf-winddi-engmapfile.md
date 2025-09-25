# EngMapFile function

## Description

The **EngMapFile** function creates or opens a file and maps it into [system space](https://learn.microsoft.com/windows-hardware/drivers/).

## Parameters

### `pwsz` [in]

Pointer to a null-terminated string that contains the fully qualified name of the file to be mapped. An example of a fully qualified file name string is *L"\\??\\c:\\test.dat".*

### `cjSize` [in]

Specifies the number of bytes of the file to map.

### `piFile` [out]

Pointer to a memory location that receives an identifier for the mapped file, provided that the mapping succeeded. If the mapping did not succeed, the memory location receives the value zero. When the mapped file needs to be released, this value should be passed to [EngUnmapFile](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engunmapfile).

## Return value

**EngMapFile** returns a pointer to the mapped view of the file if it succeeds. Otherwise, it returns **NULL**.

## Remarks

If the file already exists, **EngMapFile** opens and maps it for read/write. If the file does not exist, **EngMapFile** creates and maps it for read/write.

The value of *cjSize* affects the mapping of the file as follows:

* When *cjSize* is zero, GDI maps the file in its entirety.
* When *cjSize* is greater than the size of the file, GDI expands the file to *cjSize* bytes in size before mapping it in system memory. No assumptions should be made about the contents of memory that extend beyond the file's original size.
* When *cjSize* is less than the size of the file, GDI truncates the file to *cjSize* bytes in size before mapping it into system memory.

A driver can read and write to the file through the returned pointer.

## See also

[EngDeleteFile](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engdeletefile)

[EngUnmapFile](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engunmapfile)