# EngDeleteFile function

## Description

The **EngDeleteFile** function deletes a file.

## Parameters

### `pwszFileName` [in]

Pointer to a null-terminated string that contains the fully qualified name of the file to delete. An example of a fully qualified file name string is *L"\\??\\c:\\test.dat".*

## Return value

**EngDeleteFile** returns **TRUE** upon success. Otherwise, it returns **FALSE**.

## See also

[EngMapFile](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmapfile)