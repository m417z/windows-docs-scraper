# IOCTL_NFCSE_HCE_REMOTE_RECV IOCTL

## Description

Either returns the next data buffer available, or if there are no more buffered data, the request shall stay pending until an APDU buffer is available for reading. The data buffer shall then be returned to the caller. Note that the caller must allocate an output buffer large enough to hold the largest APDU that has been received + 4 bytes overhead.

## Parameters

### Major code

### Input buffer

None

### Input buffer length

None

### Output buffer

 A **DWORD** indicating the size of the [SECURE_ELEMENT_HCE_DATA_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfcsedev/ns-nfcsedev-_secure_element_hce_data_packet) structure plus its payload, immediately followed by the **SECURE_ELEMENT_HCE_DATA_PACKET** structure itself.

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to **STATUS_SUCCESS** if the request is successful. Possible error codes are:

| Return Code | Description |
| --- | --- |
| **STATUS_BUFFER_OVERFLOW** | The buffer supplied was too small to receive the notification, the first DWORD will contain the expected buffer size. |
| **STATUS_INVALID_PARAMETER** | If the input buffer is non-zero. |
| **STATUS_INVALID_DEVICE_STATE** | If the IOCTL is sent on a handle other than with the relative name 'SEManage'. |

## Remarks

The following are requirements that the driver must adhere to.

* This IOCTL is sent on an existing connection after HCE Activated event is triggered.
* The driver must support CancelIo on this pended IOCTL.
* The driver must maintain a “Received” queue of the received APDU for the current connection.
* When this IOCTL is received in the driver:
  + If the “Received” queue is empty, then the driver MUST pend the IOCTL for later completion.
  + If the “Received” queue is non-empty, then the driver MUST de-queue one APDU, copy the APDU buffer to the IOCTL’s output buffer, and complete the IOCTL with STATUS_SUCCESS immediately.
* If the driver completes this IOCTL with STATUS_SUCCESS, the first DWORD [4 bytes] of the output buffer MUST contain the size of the SECURE_ELEMENT_HCE_DATA_PACKET structure plus its payload.
* If a received APDU data is too large to be copied into this IOCTL's output buffer, the driver MUST copy the required buffer size into the first 4 bytes of the output buffer, set the IOCTL's information field to sizeof(DWORD), and complete the IOCTL with STATUS_BUFFER_OVERFLOW. The APDU data must be left in the "Received" queue.