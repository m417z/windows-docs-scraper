# _MS_SMHBA_SCSIENTRY structure

## Description

The MS_SMHBA_SCSIENTRY structure is used to report target LUN mapping information.

## Members

### `PortLun`

An array of MS_SMHBA_PORTLUN entries.

### `LUID`

The logical unit descriptor for the device that the operating system derives from SCSI inquiry data.

### `ScsiId`

A structure of type HBAScsiID that contains information that uniquely identifies a logical unit to the operating system.