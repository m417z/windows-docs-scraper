# IOCTL_SCSI_MINIPORT_NVCACHE IOCTL

## Description

The NV Cache Management operations that are defined here can be invoked by user-mode application code running with administrator privileges, using DeviceIoControl and the [**IOCTL_SCSI_MINIPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_miniport) control code. Or, the caller can be kernel-mode driver code using [**IoBuildDeviceIoControlRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuilddeviceiocontrolrequest) and the IOCTL_SCSI_MINIPORT control code.

The NV Cache Management function request is specified in a field in the [**NVCACHE_REQUEST_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_nvcache_request_block) structure. The input to [**IOCTL_SCSI_MINIPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_miniport) is a user-defined data structure that contains an [**SRB_IO_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_srb_io_control) structure followed by an **NVCACHE_REQUEST_BLOCK** structure. Additional function-specific data might optionally follow the **NVCACHE_REQUEST_BLOCK** structure.

The interface that is used for the NV Cache Management functionality consists of two layers. The first layer is the interface between a caller and the port driver, which is defined by [**IOCTL_SCSI_MINIPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_miniport). The second layer is the interface between the caller and the device, which is defined by the ATA8-ACS specification and IOCTL_SCSI_MINIPORT_NVCACHE. The API for user-mode application code is the DeviceIoControl interface. The API for kernel-mode driver code is the [**IoBuildDeviceIoControlRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuilddeviceiocontrolrequest) interface, which uses **IOCTL_SCSI_MINIPORT**.

## Parameters

### Major code

### Input buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains an [**SRB_IO_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_srb_io_control) structure with the Signature field set to "HYBRDISK", and the ControlCode field set to IOCTL_SCSI_MINIPORT_NVCACHE. The [**NVCACHE_REQUEST_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_nvcache_request_block) structure immediately follows the **SRB_IO_CONTROL** structure. Any optional function-specific data buffer immediately follows the **NVCACHE_REQUEST_BLOCK** structure.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** indicates the size, in bytes, of all the input data: [**SRB_IO_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_srb_io_control), [**NVCACHE_REQUEST_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_nvcache_request_block), and function-specific data buffer combined. The presence or absence of a data buffer is indicated by the **NVCACHE_REQUEST_BLOCK****DataBufSize** field.

### Output buffer

Updated [**SRB_IO_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_srb_io_control)SRB_IO_CONTROL**]() and [**NVCACHE_REQUEST_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_nvcache_request_block) structures, as well as the optional function-specific data buffer, are returned to the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

The length of the buffer.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field contains the number of bytes returned in the output buffer. The **Status** field indicates the results of the operation.

## See also

[**IOCTL_SCSI_MINIPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_miniport)

[**IoBuildDeviceIoControlRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuilddeviceiocontrolrequest)

[**NVCACHE_REQUEST_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_nvcache_request_block)

[**SRB_IO_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_srb_io_control)