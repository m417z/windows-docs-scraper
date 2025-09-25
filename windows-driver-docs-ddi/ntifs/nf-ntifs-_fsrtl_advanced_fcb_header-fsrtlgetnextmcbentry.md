# FsRtlGetNextMcbEntry function

## Description

The **FsRtlGetNextMcbEntry** routine retrieves a mapping run from a map control block (MCB). It's obsolete, but is exported to support existing driver binaries. Use [**FsRtlGetNextLargeMcbEntry**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlgetnextlargemcbentry) instead.

## Parameters

### `Mcb`

Reserved.

### `RunIndex`

Reserved.

### `Vbn`

Reserved.

### `Lbn`

Reserved.

### `SectorCount`

Reserved.

## Return value

**FsRtlGetNextMcbEntry** returns TRUE if the requested mapping run exists in the MCB; otherwise it returns FALSE.