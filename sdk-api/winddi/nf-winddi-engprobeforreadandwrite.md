# EngProbeForReadAndWrite function

## Description

The **EngProbeForReadAndWrite** function probes a structure for read and write accessibility.

## Parameters

### `Address` [in, out]

Pointer to the structure to be probed.

### `Length` [in]

Specifies the length, in bytes, of the structure to be probed.

### `Alignment` [in]

Specifies the required alignment of the structure. This parameter is expressed as the number of bytes in the base data type. For example, an alignment of 1 indicates that *Address* be aligned on a BYTE boundary, 2 specifies alignment on a WORD boundary, and 4 specifies alignment on a DWORD boundary.

## Return value

None

## Remarks

**EngProbeForReadAndWrite** causes an exception to be raised if the structure pointed to by *Address*:

* Does not have a base address that begins on an *alignment*-byte boundary.
* Is not both read- and write-accessible.

## See also

[EngProbeForRead](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engprobeforread)