# RAW_SCSI_VIRTUAL_DISK_PARAMETERS structure

## Description

Contains raw SCSI virtual disk request parameters.

## Members

### `Version`

A [RAW_SCSI_VIRTUAL_DISK_VERSION](https://learn.microsoft.com/windows/win32/api/virtdisk/ne-virtdisk-raw_scsi_virtual_disk_version) enumeration that specifies the version of the **RAW_SCSI_VIRTUAL_DISK_PARAMETERS** structure being passed to or from the VHD functions.

### `Version1`

A structure with the following members.

### `Version1.RSVDHandle`

If TRUE, indicates the operation will be transported to the virtual disk using the RSVD protocol.

### `Version1.DataIn`

If TRUE, indicates the SCSI command will read data from the DataBuffer. If FALSE, indicates data may be written.

### `Version1.CdbLength`

Length, in bytes, of the command descriptor block (CDB) contained in the CDB member.

### `Version1.SenseInfoLength`

Length, in bytes, of the sense buffer.

### `Version1.SrbFlags`

Caller-supplied SRB_FLAGS-prefixed bit flag specifying the requested operation. Flags are defined in srb.h.

### `Version1.DataTransferLength`

Length, in bytes, of the buffer to be transferred.

### `Version1.DataBuffer`

A pointer to the SCSI data buffer.

### `Version1.SenseInfo`

A pointer to a buffer to receive SCSI sense info after completion of the command.

### `Version1.Cdb`

Caller-supplied CDB data. (The CDB structure is declared in scsi.h.)