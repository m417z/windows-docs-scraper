# FsRtlLookupMcbEntry function

## Description

**FsRtlLookupMcbEntry** is obsolete, but is exported to support existing driver binaries. Use [**FsRtlLookupLargeMcbEntry**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtllookuplargemcbentry) instead.

## Parameters

### `Mcb`

Reserved.

### `Vbn`

Reserved.

### `Lbn`

Reserved.

### `SectorCount`

Reserved.

### `Index`

Reserved.

## Return value

**FsRtlLookupMcbEntry** returns TRUE if the specified VBN is within the range of VBNs that are mapped by the MCB, FALSE otherwise.