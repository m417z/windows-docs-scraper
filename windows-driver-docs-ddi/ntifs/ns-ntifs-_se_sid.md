# _SE_SID structure

## Description

The **SE_SID** union holds the maximum-sized valid Security Identifier (SID). The structure occupies 68-bytes and is suitable for stack allocation.

## Members

### `Sid`

A security identifier structure used to uniquely identify users or groups.

### `Buffer`

Specifies an array of SECURITY_MAX_SID_SIZE for allocating enough memory for the largest possible SID size.

## See also

[SID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)