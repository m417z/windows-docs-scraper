# MRxSetEaInfo routine

The*MRxSetEaInfo* routine is called by [RDBSS](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-rdbss-driver-and-library) to request that a network mini-redirector set extended attribute information on a file system object.

## Parameters

*RxContext* \[in, out\]
A pointer to the RX\_CONTEXT structure. This parameter contains the IPR that is requesting the operation.

## Return value

*MRxSetEaInfo* returns STATUS\_SUCCESS on success or an appropriate NTSTATUS value, such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_ACCESS_DENIED** | The caller lacked the proper security for this operation. |
| **STATUS_EA_TOO_LARGE** | The extended attribute information that is passed is larger than the size that is supported by the remote share. |
| **STATUS_FILE_CLOSED** | The SRV_OPEN structure was closed. |
| **STATUS_INSUFFICIENT_RESOURCES** | There were insufficient resources to complete the query. |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was specified. |
| **STATUS_NETWORK_ACCESS_DENIED** | Network access was denied. This error can be returned if the network mini-redirector was asked to set extended attributes on a read-only share. |
| **STATUS_NOT_IMPLEMENTED** | A feature that is requested, such as setting extended information on a remote page file, is not implemented. |
| **STATUS_NOT_SUPPORTED** | Extended attributes are not supported. |
| **STATUS_OBJECT_NAME_NOT_FOUND** | The object name was not found. This error can be returned if the network mini-redirector was asked to set extended attributes on a file, but the file doesn't exist. |
| **STATUS_OBJECT_PATH_NOT_FOUND** | The object path was not found. This error can be returned if an NTFS stream object was passed and the remote file system does not support streams. |
| **STATUS_ONLY_IF_CONNECTED** | The SRV_OPEN structure is not connected. |
| **STATUS_REPARSE** | A reparse is required to handle a symbolic link. |

## Remarks

RDBSS issues a call to *MRxSetEaInfo* in response to receiving an [**IRP\_MJ\_SET\_EA**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-set-ea) request.

Before calling *MRxSetEaInfo*, RDBSS modifies the following members in the RX\_CONTEXT structure pointed to by the *RxContext* parameter:

The **Info.Buffer** member is set to the user buffer from I/O request packet. This buffer has already been locked by RDBSS if needed.

The **Info.LengthRemaining** member is set to **IrpSp->Parameters.QueryEa.Length**.

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

[**MRxSetFileInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetfileinfo)

[**MRxSetFileInfoAtCleanup**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetfileinfoatcleanup)

[**MRxSetQuotaInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetquotainfo)

[**MRxSetSdInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetsdinfo)

[**MRxSetVolumeInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetvolumeinfo)

