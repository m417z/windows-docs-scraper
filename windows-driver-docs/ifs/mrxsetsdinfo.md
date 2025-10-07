# MRxSetSdInfo routine

The*MRxSetSdInfo* routine is called by [RDBSS](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-rdbss-driver-and-library) to request that a network mini-redirector set security descriptor information on a file system object.

## Parameters

*RxContext* \[in, out\]
A pointer to the RX\_CONTEXT structure. This parameter contains the IRP that is requesting the operation.

## Return value

*MRxSetSdInfo* returns STATUS\_SUCCESS on success or an appropriate NTSTATUS value, such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_ACCESS_DENIED** | The caller lacked the proper security for this operation. |
| **STATUS_CONNECTION_DISCONNECTED** | The connection was disconnected. |
| **STATUS_INSUFFICIENT_RESOURCES** | There were insufficient resources to complete the query. |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was specified. |
| **STATUS_NETWORK_ACCESS_DENIED** | Network access was denied. |
| **STATUS_NOT_IMPLEMENTED** | A feature that is requested, such as setting security information on a remote page file, is not implemented. |
| **STATUS_NOT_SUPPORTED** | Security descriptor information is not supported on the remote share. |
| **STATUS_OBJECT_PATH_NOT_FOUND** | The object path was not found. This error can be returned if security information on an NTFS stream object was requested to be set and the remote file system does not support streams. |
| **STATUS_REPARSE** | A reparse is required to handle a symbolic link. |

## Remarks

RDBSS issues a call to *MRxSetSdInfo* in response to receiving an [**IRP\_MJ\_SET\_SECURITY**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-set-security) request.

Before calling *MRxSetSdInfo*, RDBSS modifies the following members in the RX\_CONTEXT structure pointed to by the *RxContext* parameter:

The **SetSecurity.SecurityInformation** member is set to **IrpSp->Parameters.SetSecurity.SecurityInformation**.

The **SetSecurity.SecurityDescriptor** member is set to **IrpSp->Parameters.SetSecurity.SecurityDescriptor**.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Header | Mrx.h (include Mrx.h) |

## See also

[**MRxIsValidDirectory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_chkdir_calldown)

[**MRxQueryDirectory**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxquerydirectory)

[**MRxQueryEaInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxqueryeainfo)

[**MRxQueryFileInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxqueryfileinfo)

[**MRxQueryQuotaInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxqueryquotainfo)

[**MRxQuerySdInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxquerysdinfo)

[**MRxQueryVolumeInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxqueryvolumeinfo)

[**MRxSetEaInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxseteainfo)

[**MRxSetFileInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetfileinfo)

[**MRxSetFileInfoAtCleanup**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetfileinfoatcleanup)

[**MRxSetQuotaInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetquotainfo)

[**MRxSetVolumeInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetvolumeinfo)

