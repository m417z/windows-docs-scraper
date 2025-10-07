# MRxQueryQuotaInfo routine

The *MRxQueryQuotaInfo* routine is called by [RDBSS](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-rdbss-driver-and-library) to request that a network mini-redirector query quota information on a file system object.

## Parameters

*RxContext* \[in, out\]
A pointer to the RX\_CONTEXT structure. This parameter contains the IRP that is requesting the operation.

## Return value

*MRxQueryQuotaInfo* returns STATUS\_SUCCESS on success or an appropriate NTSTATUS value, such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_ACCESS_DENIED** | The caller lacked the proper security for this operation. |
| **STATUS_BUFFER_OVERFLOW** | The buffer to receive the quota information was too small.<br><br>This return value should be considered success and as much valid data as possible should be returned in the **Info.Buffer** member of the RX_CONTEXT structure pointed to by the *RxContext* parameter. |
| **STATUS_BUFFER_TOO_SMALL** | The buffer is too small to receive the requested data.<br><br>If this value is returned, the **InformationToReturn** member of the RX_CONTEXT structure pointed to by the *RxContext* parameter should be set to the minimum size of the expected buffer for the call to succeed. |
| **STATUS_CONNECTION_DISCONNECTED** | The connection was disconnected. This is an error code. |
| **STATUS_INSUFFICIENT_RESOURCES** | There were insufficient resources to complete the query. This is an error code. |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was specified. This is an error code. |
| **STATUS_NOT_SUPPORTED** | Quotas are not supported. |

## Remarks

RDBSS issues a call to *MRxQueryQuotaInfo* in response to receiving an [**IRP\_MJ\_QUERY\_QUOTA**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-query-quota) request.

Before calling *MRxQueryQuotaInfo*, RDBSS modifies the following members in the RX\_CONTEXT structure pointed to by the *RxContext* parameter:

The **Info.Buffer** member is set to user buffer from I/O request packet. This buffer has already been locked by RDBSS if needed.

The **Info.LengthRemaining** member is set to **IrpSp->Parameters.QueryQuota.Length**.

The **QueryQuota.SidList** member is set to **IrpSp->Parameters.QueryQuota.SidList**.

The **QueryQuota.SidListLength** member is set to **IrpSp->Parameters.QueryQuota.SidListLength**.

The **QueryQuota.StartSid** member is set to **IrpSp->Parameters.QueryQuota.StartSid**.

The **QueryQuota.Length** member is set to **IrpSp->Parameters.QueryQuota.Length**.

The **QueryQuota.RestartScan** member is set to nonzero if **IrpSp->Flags** has the SL\_RESTART\_SCAN bit set.

The **QueryQuota.ReturnSingleEntry** member is set to nonzero if **IrpSp->Flags** has the SL\_RETURN\_SINGLE\_ENTRY bit set.

The **QueryQuota.IndexSpecified** member is set to nonzero if **IrpSp->Flags** has the SL\_INDEX\_SPECIFIED bit set.

On success, the network mini-redirector should set the **Info.LengthRemaining** member of the RX\_CONTEXT structure to the length of the quota information to return. If the call to *MRxQueryQuotaInfo* was successful, RDBSS sets the **IoStatus.Information** member of the IRP to the **Info.LengthRemaining** member of RX\_CONTEXT.

If the call to *MRxQueryQuotaInfo* is successful, the **InformationToReturn** member of the RX\_CONTEXT structure should be set to the length of quota information returned. If the call is unsuccessful, the **InformationToReturn** member of RX\_CONTEXT should be set to zero.

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

[**MRxQuerySdInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxquerysdinfo)

[**MRxQueryVolumeInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxqueryvolumeinfo)

[**MRxSetEaInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxseteainfo)

[**MRxSetFileInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetfileinfo)

[**MRxSetFileInfoAtCleanup**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetfileinfoatcleanup)

[**MRxSetQuotaInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetquotainfo)

[**MRxSetSdInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetsdinfo)

[**MRxSetVolumeInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetvolumeinfo)

