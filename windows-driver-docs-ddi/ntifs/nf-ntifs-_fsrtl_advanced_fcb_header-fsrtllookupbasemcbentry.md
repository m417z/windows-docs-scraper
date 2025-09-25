# FsRtlLookupBaseMcbEntry function

## Description

The **FsRtlLookupBaseMcbEntry** routine retrieves the mapping of a virtual block number (VBN) to a logical block number (LBN) from a map control block (MCB). It indicates if the mapping exists and the size of the run.

## Parameters

### `Mcb`

Supplies the Mcb being examined.

### `Vbn`

Supplies the Vbn to lookup.

### `Lbn`

Receives the Lbn corresponding to the Vbn. A value of -1 is returned if the Vbn does not have a corresponding Lbn.

### `SectorCountFromLbn`

Receives the number of sectors that map from the Vbn to contiguous Lbn values beginning with the input Vbn.

### `StartingLbn`

Contains the lbn at the start of the run. If it's a hole then the starting Lbn is zero.

### `SectorCountFromStartingLbn`

Contains the number of sectors at the start of the run if a sector count argument is present.

### `Index`

Receives the index of the run found.

## Return value

This function returns TRUE if the Vbn is within the range of VBNs mapped by the MCB (even if it corresponds to a hole in the mapping), and FALSE if the Vbn is beyond the range of the MCB's mapping.

For example, if an MCB has a mapping for VBNs 5 and 7 but not for 6, then a lookup on Vbn 5 or 7 will yield a non zero Lbn and a sector count of 1. A lookup for Vbn 6 will return TRUE with an Lbn value of 0, and lookup for Vbn 8 or above will return FALSE.