# MRxQuerySdInfo routine

The*MRxQuerySdInfo* routine is called by [RDBSS](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-rdbss-driver-and-library) to request that a network mini-redirector query security descriptor information on a file system object.

## Parameters

*RxContext* \[in, out\]
A pointer to the RX\_CONTEXT structure. This parameter contains the IRP that is requesting the operation.

## Return value

*MRxQuerySdInfo* returns STATUS\_SUCCESS on success or an appropriate NTSTATUS value, such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_ACCESS_DENIED** | The caller lacked the proper security for this operation. |
| **STATUS_BUFFER_OVERFLOW** | The buffer to receive the security descriptor information was too small.<br><br>This return value should be considered success and as much valid data as possible should be returned in the **Info.Buffer** member of the RX_CONTEXT structure pointed to by the *RxContext* parameter. |
| **STATUS_BUFFER_TOO_SMALL** | The buffer is too small to receive the requested data.<br><br>If this value is returned, the **InformationToReturn** member of the RX_CONTEXT structure pointed to by the *RxContext* parameter should be set to the minimum size of the expected buffer for the call to succeed. |
| **STATUS_CONNECTION_DISCONNECTED** | The connection was disconnected. |
| **STATUS_INSUFFICIENT_RESOURCES** | There were insufficient resources to complete the query. |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was specified. |
| **STATUS_NETWORK_ACCESS_DENIED** | Network access was denied. |
| **STATUS_NOT_IMPLEMENTED** | A feature that is requested, such as information on a remote page file, is not implemented. |
| **STATUS_NOT_SUPPORTED** | Security descriptor information is not supported on the remote share. |
| **STATUS_OBJECT_PATH_NOT_FOUND** | The object path was not found. This error can be returned if information on an NTFS stream object was requested and the remote file system does not support streams. |
| **STATUS_REPARSE** | A reparse is required to handle a symbolic link. |

## Remarks

RDBSS issues a call to *MRxQuerySdInfo* in response to receiving an [**IRP\_MJ\_QUERY\_SECURITY**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-query-security) request.

Before calling *MRxQuerySdInfo*, RDBSS modifies the following members in the RX\_CONTEXT structure pointed to by the *RxContext* parameter:

The **QuerySecurity.SecurityInformation** member is set to **IrpSp->Parameters.QuerySecurity.SecurityInformation**.

The **Info.Buffer** member is set to user buffer from I/O request packet. This buffer has already been locked by RDBSS if needed.

The **Info.LengthRemaining** member is set to **IrpSp->Parameters.QuerySecurity.Length**.

On success, the network mini-redirector should set the **InformationToReturn** member of the RX\_CONTEXT structure to the length of the security information returned. If the call to *MRxQuerySdInfo* was successful, RDBSS sets the **IoStatus.Information** member of the IRP to the **InformationToReturn** member of RX\_CONTEXT.

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

[**MRxQueryVolumeInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxqueryvolumeinfo)

[**MRxSetEaInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxseteainfo)

[**MRxSetFileInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetfileinfo)

[**MRxSetFileInfoAtCleanup**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetfileinfoatcleanup)

[**MRxSetQuotaInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetquotainfo)

[**MRxSetSdInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetsdinfo)

[**MRxSetVolumeInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetvolumeinfo)

