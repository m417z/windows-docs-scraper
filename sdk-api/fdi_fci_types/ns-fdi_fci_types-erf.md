# ERF structure

## Description

[This structure contains information required by the **Extract** function, which is not supported. This documentation is provided for informational purposes only.]

The **ERF** structure contains error information from FCI/FDI. The caller should not modify this structure.

## Members

### `erfOper`

An FCI/FDI error code.

The following values are returned for FCI:

| Value | Meaning |
| --- | --- |
| **FCIERR_NONE**<br><br>0x00 | No Error. |
| **FCIERR_OPEN_SRC**<br><br>0x01 | Failure opening the file to be stored in the cabinet. |
| **FCIERR_READ_SRC**<br><br>0x02 | Failure reading the file to be stored in the cabinet. |
| **FCIERR_ALLOC_FAIL**<br><br>0x03 | Out of memory in FCI. |
| **FCIERR_TEMP_FILE**<br><br>0x04 | Could not create a temporary file. |
| **FCIERR_BAD_COMPR_TYPE**<br><br>0x05 | Unknown compression type. |
| **FCIERR_CAB_FILE**<br><br>0x06 | Could not create the cabinet file. |
| **FCIERR_USER_ABORT**<br><br>0x07 | FCI aborted. |
| **FCIERR_MCI_FAIL**<br><br>0x08 | Failure compressing data. |
| **FCIERR_CAB_FORMAT_LIMIT**<br><br>0x09 | Data-size or file-count exceeded CAB format limits. |

The following values are returned for FDI:

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

### `erfType`

An optional error value filled in by FCI/FDI. For FCI, this is usually the C runtime errno value.

### `fError`

A flag that indicates an error. If **TRUE**, an error is present.

## See also

[Extract](https://learn.microsoft.com/windows/desktop/DevNotes/extract)