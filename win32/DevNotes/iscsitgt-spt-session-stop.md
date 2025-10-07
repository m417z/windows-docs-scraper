# ISCSITGT\_SPT\_SESSION\_STOP structure

\[The following structure is available for use in Windows Server 2012 R2. It may be altered or unavailable in subsequent versions.\]

Used with the [**IOCTL\_SCSI\_MINIPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_miniport) IOCTL and the CTLCODE\_ISCSITGT\_SPT\_SESSION\_END (0x101) control code to stop a session.

## Members

**Header**

Mandatory header.

**ITNexusHandle**

An opaque handle representing a session.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------|
| Minimum supported client<br> | None supported<br> |
| Minimum supported server<br> | Windows Server 2012 R2 \[desktop apps only\]<br> |
| End of client support<br> | None supported<br> |
| End of server support<br> | Windows Server 2012 R2<br> |

## See also

[iSCSI Target Pass-Through](https://learn.microsoft.com/powershell/module/iscsi)

[**SRB\_IO\_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_srb_io_control)

