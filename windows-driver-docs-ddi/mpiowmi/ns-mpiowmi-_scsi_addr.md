# _SCSI_ADDR structure

## Description

The SCSI_ADDR structure represents a SCSI address.

## Members

### `PortNumber`

An unsigned 8-bitfield that represents the PortNumber as defined by the SCSI_ADDRESS structure in *Ntddscsi.h*.

### `ScsiPathId`

An unsigned 8-bitfield that represents the PathId as defined by the SCSI_ADDRESS structure in *Ntddscsi.h*.

### `TargetId`

An unsigned 8-bitfield that represents the TargetId as defined by the SCSI_ADDRESS structure in *Ntddscsi.h*.

### `Lun`

An unsigned 8-bitfield that represents the Lun as defined by the SCSI_ADDRESS structure in *Ntddscsi.h*.