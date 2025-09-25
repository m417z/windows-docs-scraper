# IOCTL_DISK_RESET_SNAPSHOT_INFO IOCTL

## Description

Clears all volume shadow copy service (VSS) hardware-based snapshot information from the disk. A snapshot is also known as a shadow copy. This request is available in Windows Vista and later versions of the Windows operating systems. The caller must be running at IRQL = PASSIVE_LEVEL.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** member is set to zero. The **Status** member is set to STATUS_SUCCESS if the operation was successful. Otherwise, the **Status** member is set to the appropriate error code.

## Remarks

This I/O control code can be issued from either a kernel-mode driver or a user-mode application. When this I/O control code is issued from a kernel-mode driver, the caller provides an I/O Request Packet (IRP) that contains an IO_STATUS_BLOCK data structure. This data structure is used to return error information to the caller. When this I/O control code is issued from a user-mode application with the **DeviceIocontrol** routine, the caller can obtain error information by calling the **GetLastError** routine.

The disk whose handle is used when this IOCTL is issued might be in the offline state when the IOCTL is issued. If the disk is put in the offline state by using the disk manager Microsoft Management Console (MMC) snap-in, the disk will have its read-only attribute set, which will cause this IOCTL to fail. However, if the disk partition utility (Diskpart.exe) is used to put the disk in the offline state, the read-only attribute for the disk is not set. For this reason, it is best to use the disk partition utility to put a disk in the offline state.

**Note** A side effect of using this IOCTL is that Disk Management tools may report an additional partition of the type "UNKNOWN" on GPT disks. This 256 kilobyte partition is created by the IOCTL operation and is a snapshot partition used in the restore process. This partition is expected and can be ignored by system administrators.