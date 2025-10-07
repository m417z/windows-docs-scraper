# MRxQueryFileInfo routine

The*MRxQueryFileInfo* routine is called by [RDBSS](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-rdbss-driver-and-library) to request that a network mini-redirector query file information on a file system object.

## Parameters

*RxContext* \[in, out\]
A pointer to the RX\_CONTEXT structure. This parameter contains the IRP that is requesting the operation.

## Return value

*MRxQueryFileInfo* returns STATUS\_SUCCESS on success or an appropriate NTSTATUS value, such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_ACCESS_DENIED** | The caller lacked the proper security for this operation. |
| **STATUS_BUFFER_OVERFLOW** | The buffer to receive the file information was too small.<br><br>This return value should be considered success and as much valid data as possible should be returned in the **Info.Buffer** member of the RX_CONTEXT structure pointed to by the *RxContext* parameter. |
| **STATUS_BUFFER_TOO_SMALL** | The buffer is too small to receive the requested data.<br><br>If this value is returned, the **InformationToReturn** member of the RX_CONTEXT structure pointed to by the *RxContext* parameter should be set to the minimum size of the expected buffer for the call to succeed. |
| **STATUS_INSUFFICIENT_RESOURCES** | There were insufficient resources to complete the query. |
| **STATUS_INVALID_NETWORK_RESPONSE** | An invalid file information buffer was received from the remote server. |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was specified.<br><br>This value can be returned if an invalid value for the **FileInformationClass** member in the RX_CONTEXT is passed. This value can also be returned if the **FileInformationClass** member specified is for **FileStreamInformation** and the remote file system does not support streams. |
| **STATUS_OBJECT_NAME_NOT_FOUND** | The object name was not found. This is an error code. |

## Remarks

RDBSS issues a call to *MRxQueryFileInfo* in response to receiving an [**IRP\_MJ\_QUERY\_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-query-information) request.

Before calling *MRxQueryFileInfo*, RDBSS modifies the following members in the RX\_CONTEXT structure pointed to by the *RxContext* parameter:

The **Info.FileInformationClass** member is set to **IrpSp->Parameters.QueryFile.FileInformationClass**, the requested FILE\_INFORMATION\_CLASS value.

The **Info.Buffer** member is set to the user buffer from the I/O request packet.

The **Info.LengthRemaining** member is set to **IrpSp->Parameters.QueryFile.Length**.

The **QueryDirectory.FileIndex** member is set to **IrpSp->Parameters.QueryDirectory.FileIndex**.

The **QueryDirectory.RestartScan** member is set if **IrpSp->Flags** has the SL\_RESTART\_SCAN bit set.

The **QueryDirectory.ReturnSingleEntry** member is set if **IrpSp->Flags** has SL\_RETURN\_SINGLE\_ENTRY bit set.

The **QueryDirectory.InitialQuery** member is set if **Fobx->UnicodeQueryTemplate.Buffer** is **NULL** and **Fobx->Flags** does not have the FOBX\_FLAG\_MATCH\_ALL bit set.

On success, the network mini-redirector should set the **Info.LengthRemaining** member of the RX\_CONTEXT structure to **Info.Length** member minus the length of the file information returned. If the call to *MRxQueryFileInfo* was successful, RDBSS sets the **IoStatus.Information** member of the IRP to **IrpSp->Parameters.QueryFile.Length** minus the **Info.LengthRemaining** member of RX\_CONTEXT.

RDBSS does not support requests with the SL\_INDEX\_SPECIFIED bit of the **IrpSp->Flags** set. A network mini-redirector will not receive calls to *MRxQueryFileInfo* with the SL\_INDEX\_SPECIFIED bit of **IrpSp->Flags** set.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Header | Mrx.h (include Mrx.h) |

## See also

[**MRxIsValidDirectory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_chkdir_calldown)

[**MRxQueryDirectory**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxquerydirectory)

[**MRxQueryEaInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxqueryeainfo)

[**MRxQueryQuotaInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxqueryquotainfo)

[**MRxQuerySdInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxquerysdinfo)

[**MRxQueryVolumeInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxqueryvolumeinfo)

[**MRxSetEaInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxseteainfo)

[**MRxSetFileInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetfileinfo)

[**MRxSetFileInfoAtCleanup**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetfileinfoatcleanup)

[**MRxSetQuotaInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetquotainfo)

[**MRxSetSdInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetsdinfo)

[**MRxSetVolumeInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetvolumeinfo)

