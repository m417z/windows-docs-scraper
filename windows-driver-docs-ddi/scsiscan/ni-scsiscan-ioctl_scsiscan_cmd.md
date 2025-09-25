# IOCTL_SCSISCAN_CMD IOCTL

## Description

Creates a customized SCSI control descriptor block (CDB) and sends it to the kernel-mode still image driver for SCSI buses.

## Parameters

### Major code

### Input buffer

Pointer to a **SCSISCAN_CMD** structure.

### Input buffer length

Size of the input buffer.

### Output buffer

Pointer to a data buffer. Depending on the type of I/O operation, this buffer might supply or receive data.

### Output buffer length

Size of the output buffer.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.

## Remarks

When the **DeviceloControl** function is called with the IOCTL_SCSISCAN_CMD I/O control code, the caller must specify the address of a [SCSISCAN_CMD](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiscan/ns-scsiscan-_scsiscan_cmd) structure as the function's *lpInBuffer* parameter. This structure specifies the type of operation being requested. The kernel-mode driver constructs a SCSI Request Block (SRB) from the SCSISCAN_CMD structure's contents.

For SCSI commands that involve data transfers, the [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function's *lpOutBuffer* must point to a data buffer. For read operations, this buffer will receive data read from the device. For write operations, the buffer must contain the data to be written.

For more information, see [Accessing Kernel-Mode Drivers for Still Image Devices](https://learn.microsoft.com/windows-hardware/drivers/image/accessing-kernel-mode-drivers-for-still-image-devices).

### Code example

```cpp
SCSISCAN_CMD  Cmd;
UCHAR         SrbStatus;

// Construct the SCSISCAN_CMD structure and
// clear out the sense buffer.
memset(&Cmd, 0, sizeof(Cmd));
memset(SenseBuffer,0, sizeof(SenseBuffer));

Cmd.Size = sizeof(SCSISCAN_CMD);
Cmd.SrbFlags = SRB_FLAGS_DATA_OUT;
Cmd.CdbLength = 6;
Cmd.SenseLength = 18;
Cmd.TransferLength = len;
Cmd.pSrbStatus = &SrbStatus;
Cmd.pSenseBuffer = SenseBuffer;

Cmd.Cdb[0] = 0x0A;
Cmd.Cdb[4] = ((PFOUR_BYTE)&len) -> Byte0;
Cmd.Cdb[3] = ((PFOUR_BYTE)&len) -> Byte1;
Cmd.Cdb[2] = ((PFOUR_BYTE)&len) -> Byte2;
Cmd.Cdb[5] = 0;

DeviceIoControl(
           gb_Scan_Handle,
           (DWORD) IOCTL_SCSISCAN_CMD,
           &Cmd,
           sizeof(Cmd),
           buf,
           len,
           amount_written_ptr,
           NULL
           );

if (SRB_STATUS_SUCCESS != SRB_STATUS(SrbStatus))
{
  fprintf(stderr, "WriteScanner error.\n");
  if (SRB_STATUS_DATA_OVERRUN == SrbStatus)
  {
    fprintf(stderr, "Data over/under run. This is ok.\n");
  }
  else if ((SenseBuffer[2] & 0xf) == SCSI_SENSE_UNIT_ATTENTION)
  {
    fprintf(stderr, "Unit attention.  Retrying request....\n");
    memset(SenseBuffer,0, sizeof(SenseBuffer));
    SrbStatus = 0;
    DeviceIoControl(
      gb_Scan_Handle,
      (DWORD) IOCTL_SCSISCAN_CMD,
      &Cmd,
      sizeof(Cmd),
      buf,
      len,
      amount_written_ptr,
      NULL
      );
    }
  }
}
```

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)