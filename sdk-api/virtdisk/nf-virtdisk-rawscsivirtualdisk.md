# RawSCSIVirtualDisk function

## Description

Issues an embedded SCSI request directly to a virtual hard disk.

## Parameters

### `VirtualDiskHandle` [in]

A handle to an open virtual disk. For information on how to open a virtual disk, see the
[OpenVirtualDisk](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-openvirtualdisk) function. This handle may also be a handle to a Remote Shared Virtual Disk. For information on how to open a Remote Shared Virtual Disk, see the [Remote Shared Virtual Disk Protocol](https://learn.microsoft.com/openspecs/windows_protocols/ms-rsvd/c865c326-47d6-4a91-a62d-0e8f26007d15) documentation.

### `Parameters` [in]

A pointer to a valid [RAW_SCSI_VIRTUAL_DISK_PARAMETERS](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-raw_scsi_virtual_disk_parameters) structure that contains snapshot deletion data.

### `Flags` [in]

SCSI virtual disk flags, which must be a valid combination of the [RAW_SCSI_VIRTUAL_DISK_FLAG](https://learn.microsoft.com/windows/win32/api/virtdisk/ne-virtdisk-raw_scsi_virtual_disk_flag) enumeration.

### `Response` [out]

A pointer to a [RAW_SCSI_VIRTUAL_DISK_RESPONSE](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-raw_scsi_virtual_disk_response) structure that contains the results of processing the SCSI command.

## Return value

Status of the request.

If the function succeeds, the return value is **ERROR_SUCCESS**.

A return of **ERROR_SUCCESS** only means the request was received by the virtual disk. The SCSI command itself could have failed due to an invalid device state, an unsupported SCSI command, or another error.

If the function fails, the return value is an error code. For more information, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).