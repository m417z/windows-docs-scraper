# IOCTL_CDROM_GET_LAST_SESSION IOCTL

## Description

Queries the device for the first complete session number, the last complete session number, and the last complete session starting address. This request is the same as an [IOCTL_CDROM_READ_TOC_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_read_toc_ex) request with a format of CDROM_READ_TOC_EX_FORMAT_SESSION. For more information on the CDROM_READ_TOC_EX_FORMAT_SESSION format, see the description of the **Format** member of the [CDROM_READ_TOC_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_read_toc_ex) structure.

On output, if the value in the **FirstCompleteSession** member of [CDROM_TOC_SESSION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_toc_session_data) is the same as the value in the **LastCompleteSession** member, the disc is not multisession.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The driver returns the query data in a [CDROM_TOC_SESSION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_toc_session_data) structure at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

Length of a [CDROM_TOC_SESSION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_toc_session_data) structure.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes returned. The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_BUFFER_TOO_SMALL or STATUS_INSUFFICIENT_RESOURCES.

## Remarks