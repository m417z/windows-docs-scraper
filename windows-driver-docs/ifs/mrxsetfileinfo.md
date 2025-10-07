# MRxSetFileInfo routine

The *MRxSetFileInfo* routine is called by [RDBSS](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-rdbss-driver-and-library) to request that a network mini-redirector set file information on a file system object.

## Parameters

*RxContext* \[in, out\]
A pointer to the RX\_CONTEXT structure. This parameter contains the IRP that is requesting the operation.

## Return value

*MRxSetFileInfo* returns STATUS\_SUCCESS on success or an appropriate NTSTATUS value, such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_ACCESS_DENIED** | The caller lacked the proper security for this operation. |
| **STATUS_INSUFFICIENT_RESOURCES** | There were insufficient resources to complete the query. |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was specified. |
| **STATUS_NETWORK_ACCESS_DENIED** | Network access was denied. This error can be returned if the network mini-redirector was asked to set file information on a read-only share. |
| **STATUS_NOT_IMPLEMENTED** | A feature that is requested, such as setting file information on a remote page file, is not implemented. |
| **STATUS_OBJECT_NAME_NOT_FOUND** | The object name was not found. This error can be returned if the network mini-redirector was asked to set file information on a file, but the file doesn't exist. |
| **STATUS_OBJECT_PATH_NOT_FOUND** | The object path was not found. This error can be returned if an NTFS stream object was passed and the remote file system does not support streams. |
| **STATUS_ONLY_IF_CONNECTED** | The SRV_OPEN structure is not connected. |
| **STATUS_REPARSE** | A reparse is required to handle a symbolic link. |

## Remarks

RDBSS issues a call to *MRxSetFileInfo* in response to receiving an [**IRP\_MJ\_SET\_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-set-information) request.

Before calling *MRxSetFileInfo*, RDBSS modifies the following members in the RX\_CONTEXT structure pointed to by the *RxContext* parameter:

The **Info.FileInformationClass** member is set to **IrpSp->Parameters.SetFile.FileInformationClass**, the specified FILE\_INFORMATION\_CLASS value.

The **Info.Buffer** member is set to **Irp->AssociatedIrp.SystemBuffer**.

The **Info.Length** member is set to **IrpSp->Parameters.SetFile.Length**.

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

[**MRxSetFileInfoAtCleanup**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetfileinfoatcleanup)

[**MRxSetQuotaInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetquotainfo)

[**MRxSetSdInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetsdinfo)

[**MRxSetVolumeInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetvolumeinfo)

