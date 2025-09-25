# FDINOTIFICATION structure

## Description

The **FDINOTIFICATION** structure to provide information to [FNFDINOTIFY](https://learn.microsoft.com/windows/desktop/api/fdi/nf-fdi-fnfdinotify).

## Members

### `cb`

The size, in bytes, of a cabinet element.

### `psz1`

A null-terminated string.

### `psz2`

A null-terminated string.

### `psz3`

A null-terminated string.

### `pv`

Pointer to an application-defined value.

### `hf`

Application-defined value used to identify the opened file.

### `date`

The MS-DOS date.

| Bits | Description |
| --- | --- |
| 0-4 | Day of the month (1-31) |
| 5-8 | Month (1 = January, 2 = February, etc.) |
| 9-15 | Year offset from 1980 (add 1980 |

### `time`

The MS-DOS time.

| Bits | Description |
| --- | --- |
| 0-4 | Second divided by 2 |
| 5-10 | Minute (0-59) |
| 11-15 | Hour (0-23 on a 24-hour clock) |

### `attribs`

The file attributes. For possible values and their descriptions, see File Attributes.

### `setID`

The identifier for a cabinet set.

### `iCabinet`

The number of the cabinets within a set.

### `iFolder`

The number of folders within a cabinet.

### `fdie`

An FDI error code. Possible values include:

| Value | Meaning |
| --- | --- |
| **FDIERROR_NONE**<br><br>0x00 | No error. |
| **FDIERROR_CABINET_NOT_FOUND**<br><br>0x01 | The cabinet file was not found. |
| **FDIERROR_NOT_A_CABINET**<br><br>0x02 | The cabinet file does not have the correct format. |
| **FDIERROR_UNKNOWN_CABINET_VERSION**<br><br>0x03 | The cabinet file has an unknown version number. |
| **FDIERROR_CORRUPT_CABINET**<br><br>0x04 | The cabinet file is corrupt. |
| **FDIERROR_ALLOC_FAIL**<br><br>0x05 | Insufficient memory. |
| **FDIERROR_BAD_COMPR_TYPE**<br><br>0x06 | Unknown compression type used in the cabinet folder. |
| **FDIERROR_MDI_FAIL**<br><br>0x07 | Failure decompressing data from the cabinet file. |
| **FDIERROR_TARGET_FILE**<br><br>0x08 | Failure writing to the target file. |
| **FDIERROR_RESERVE_MISMATCH**<br><br>0x09 | The cabinets within a set do not have the same RESERVE sizes. |
| **FDIERROR_WRONG_CABINET**<br><br>0x0A | The cabinet returned by fdintNEXT_CABINET is incorrect. |
| **FDIERROR_USER_ABORT**<br><br>0x0B | FDI aborted. |

## See also

[FNFDINOTIFY](https://learn.microsoft.com/windows/desktop/api/fdi/nf-fdi-fnfdinotify)