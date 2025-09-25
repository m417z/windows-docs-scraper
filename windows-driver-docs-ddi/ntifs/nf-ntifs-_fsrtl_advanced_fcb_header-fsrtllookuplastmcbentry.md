# FsRtlLookupLastMcbEntry function

## Description

The **FsRtlLookupLastMcbEntry** routine retrieves the last mapping entry stored in the map control block (MCB). It's obsolete, but is exported to support existing driver binaries. Use [**FsRtlLookupLastLargeMcbEntry**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtllookuplastlargemcbentry) instead.

## Parameters

### `Mcb`

Reserved.

### `Vbn`

Reserved.

### `Lbn`

Reserved.

## Return value

**FsRtlGetNextLargeMcbEntry** returns TRUE if the requested mapping run exists in the MCB, FALSE otherwise.