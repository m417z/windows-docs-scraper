# RAW_SCSI_VIRTUAL_DISK_RESPONSE structure

## Description

Contains raw SCSI virtual disk response parameters.

## Members

### `Version`

A [RAW_SCSI_VIRTUAL_DISK_PARAMETERS](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-raw_scsi_virtual_disk_parameters) structure being passed to or from the VHD functions.

### `Version1`

A structure with the following member.

### `Version1.ScsiStatus`

A SRB_STATUS-prefixed status value (defined in srb.h).

### `Version1.SenseInfoLength`

Length, in bytes, of the sense buffer.

### `Version1.DataTransferLength`

Length, in bytes, of the buffer to be transferred.