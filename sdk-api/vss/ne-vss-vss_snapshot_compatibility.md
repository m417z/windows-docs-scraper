# VSS_SNAPSHOT_COMPATIBILITY enumeration

## Description

The **VSS_SNAPSHOT_COMPATIBILITY** enumeration
indicates which volume control or file I/O operations are disabled for the volume that has been shadow copied.

## Constants

### `VSS_SC_DISABLE_DEFRAG:0x1`

The provider managing the shadow copies for a specified volume does not support defragmentation operations
on that volume.

### `VSS_SC_DISABLE_CONTENTINDEX:0x2`

The provider managing the shadow copies for a specified volume does not support content index operations on
that volume.