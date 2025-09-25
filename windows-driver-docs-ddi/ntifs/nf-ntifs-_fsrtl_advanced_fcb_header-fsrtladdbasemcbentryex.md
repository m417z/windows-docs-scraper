# FsRtlAddBaseMcbEntryEx function

## Description

The FsRtlAddBaseMcbEntryEx function is used to add a new mapping of virtual block numbers (VBN's) to logical block numbers (LBN's) to an existing map control block (MCB).

## Parameters

### `Mcb`

Supplies the Mcb in which to add the new mapping.

### `Vbn`

Supplies the starting VBN of the new mapping run to add to the Mcb.

### `Lbn`

Supplies the starting Lbn of the new mapping run to add to the Mcb.

### `SectorCount`

Supplies the size of the new mapping run (in sectors).

## Return value

This function returns one of the following NTSTATUS values:

Status|Meaning
---|----
STATUS_SUCCESSFUL|the mapping was added successfully (i.e., the new VBNs did not collide with existing VBNs),
STATUS_INSUFFICIENT_RESOURCES|There wasn't memory to add the new mapping.
STATUS_UNSUCCESSFULL|There was a collision with the new VBN's and existing VBN's.

## Remarks

The mapping for the VBNs must not already exist in the Mcb. If the
mapping continues a previous run, then this routine will actually coalesce
them into 1 run.

If pool is not available to store the information this routine will raise a
status value indicating insufficient resources.

An input Lbn value of zero is illegal (i.e., the Mcb structure will never
map a VBN to a zero Lbn value).

## See also