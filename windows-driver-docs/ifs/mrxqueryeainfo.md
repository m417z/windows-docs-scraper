# MRxQueryEaInfo routine

The *MRxQueryEaInfo* routine is called by [RDBSS](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-rdbss-driver-and-library) to request that a network mini-redirector query extended attribute information on a file system object.

## Parameters

*RxContext* \[in, out\]
A pointer to the RX\_CONTEXT structure. This parameter contains the IRP that is requesting the operation.

## Return value

*MRxQueryEaInfo* returns STATUS\_SUCCESS on success or an appropriate NTSTATUS value, such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_ACCESS_DENIED** | The caller lacked the proper security for this operation. |
| **STATUS_BUFFER_OVERFLOW** | The buffer to receive the extended attribute information was too small.<br><br>This return value should be considered success and as much valid data as possible should be returned in the **Info.Buffer** member of the RX_CONTEXT structure pointed to by the *RxContext* parameter. |
| **STATUS_BUFFER_TOO_SMALL** | The buffer is too small to receive the requested data.<br><br>If this value is returned, the **InformationToReturn** member of the RX_CONTEXT structure pointed to by the *RxContext* parameter should be set to the minimum size of the expected buffer for the call to succeed. |
| **STATUS_CONNECTION_DISCONNECTED** | The connection was disconnected. |
| **STATUS_EA_CORRUPT_ERROR** | Invalid extended attribute information was received from the remote server. |
| **STATUS_INSUFFICIENT_RESOURCES** | There were insufficient resources to complete the query. |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was specified. |
| **STATUS_NONEXISTENT_EA_ENTRY** | There are no extended attributes on the file object and the user supplied an extended attribute index. |
| **STATUS_NOT_SUPPORTED** | Extended attributes are not supported. |
| **STATUS_ONLY_IF_CONNECTED** | The SRV_OPEN structure is not connected. |
| **STATUS_REQUEST_ABORTED** | The network request was aborted. |

## Remarks

RDBSS issues a call to *MRxQueryEaInfo* in response to receiving an [**IRP\_MJ\_QUERY\_EA**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-query-ea) request.

Before calling *MRxQueryEaInfo*, RDBSS modifies the following members in the RX\_CONTEXT structure pointed to by the *RxContext* parameter:

The **Info.Buffer** member is set to the user buffer from I/O request packet. This buffer has already been locked by RDBSS if needed.

The **Info.LengthRemaining** member is set to **IrpSp->Parameters.QueryEa.Length**.

The **QueryEa.UserEaList** member is set to **IrpSp->Parameters.QueryEa.EaList**.

The **QueryEa.UserEaListLength** member is set to **IrpSp->Parameters.QueryEa.EaListLength**.

The **QueryEa.UserEaIndex** member is set to **IrpSp->Parameters.QueryEa.EaIndex**.

The **QueryEa.RestartScan** member is set to nonzero if **IrpSp->Flags** has the SL\_RESTART\_SCAN bit on.

The **QueryEa.ReturnSingleEntry** member is set to nonzero if **IrpSp->Flags** has the SL\_RETURN\_SINGLE\_ENTRY bit on.

The **QueryEa.IndexSpecified** member is set to nonzero if **IrpSp->Flags** has the SL\_INDEX\_SPECIFIED bit on.

On success, *MRxQueryEaInfo* should set the **Info.LengthRemaininging** member of the RX\_CONTEXT structure to the length of extended attribute information returned and also update the **Fobx->OffsetOfNextEaToReturn** member. If the call to *MRxQueryEaInfo* was successful, RDBSS sets the **IoStatus.Information** member of the IRP to **IrpSp->Parameters.QueryEa.Length** minus the **Info.LengthRemaining** member of RX\_CONTEXT.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Header | Mrx.h (include Mrx.h) |

## See also

[**MRxIsValidDirectory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_chkdir_calldown)

[**MRxQueryDirectory**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxquerydirectory)

[**MRxQueryFileInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxqueryfileinfo)

[**MRxQueryQuotaInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxqueryquotainfo)

[**MRxQuerySdInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxquerysdinfo)

[**MRxQueryVolumeInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxqueryvolumeinfo)

[**MRxSetEaInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxseteainfo)

[**MRxSetFileInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetfileinfo)

[**MRxSetFileInfoAtCleanup**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetfileinfoatcleanup)

[**MRxSetQuotaInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetquotainfo)

[**MRxSetSdInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetsdinfo)

[**MRxSetVolumeInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetvolumeinfo)

