# MODLOAD_DATA structure

## Description

Contains module data.

## Members

### `ssize`

The size of this structure, in bytes.

### `ssig`

The type of data. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **DBHHEADER_DEBUGDIRS**<br><br>0x1 | The **data** member is a buffer that contains an array of [IMAGE_DEBUG_DIRECTORY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-image_debug_directory) structures. |
| **DBHHEADER_CVMISC**<br><br>0x2 | The **data** member is a buffer that contains an array of [MODLOAD_CVMISC](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-modload_cvmisc) structures. |

### `data`

The data. The format of this data depends on the value of the **ssig** member.

### `size`

The size of the **data** buffer, in bytes.

### `flags`

This member is unused.

## See also

[IMAGE_DEBUG_DIRECTORY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-image_debug_directory)

[MODLOAD_CVMISC](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-modload_cvmisc)

[SymLoadModuleEx](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symloadmoduleex)