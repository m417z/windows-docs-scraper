# MRxQueryDirectory routine

The *MRxQueryDirectory* routine is called by [RDBSS](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-rdbss-driver-and-library) to request that a network mini-redirector query information on a file directory.

## Parameters

*RxContext* \[in, out\]
A pointer to the RX\_CONTEXT structure. This parameter contains the IRP that is requesting the operation.

## Return value

*MRxQueryDirectory* returns STATUS\_SUCCESS on success or an appropriate NTSTATUS value, such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_ACCESS_DENIED** | The caller lacked the proper security for this operation. |
| **STATUS_INSUFFICIENT_RESOURCES** | There were insufficient resources to complete the query. |
| **STATUS_INVALID_NETWORK_RESPONSE** | An invalid file information buffer was received from the remote server or a filename length that was returned exceeded the maximum allowed length. |
| **STATUS_INVALID_PARAMETER** | An invalid FileInformationClass was specified in the **Info.FileInformationClass** member in the RX_CONTEXT structure pointed to by the *RxContext* parameter. |
| **STATUS_LINK_FAILED** | The attempt to reconnect to a remote server to complete the query failed. |
| **STATUS_NO_SUCH_FILE** | The query failed to find any entries. |
| **STATUS_SHARING_VIOLATION** | A sharing violation occurred. |

## Remarks

Before calling *MRxQueryDirectory*, RDBSS modifies the following members in the RX\_CONTEXT structure pointed to by the *RxContext* parameter:

The **Info.FileInformationClass** member is set to **IrpSp->Parameters.QueryDirectory.FileInformationClass**.

The **Info.Buffer** member is set to user buffer from I/O request packet. This buffer has already been locked by RDBSS if needed.

The **Info.LengthRemaining** member is set to **IrpSp->Parameters.QueryDirectory.Length**.

The **QueryDirectory.FileIndex** member is set to **IrpSp->Parameters.QueryDirectory.FileIndex**.

The **QueryDirectory.RestartScan** member is set to nonzero if **IrpSp->Flags** has the SL\_RESTART\_SCAN bit on.

The **QueryDirectory.ReturnSingleEntry** member is set to nonzero if **IrpSp->Flags** has the SL\_RETURN\_SINGLE\_ENTRY bit on.

The **QueryDirectory.IndexSpecified** member is set to nonzero if **IrpSp->Flags** has the SL\_INDEX\_SPECIFIED bit on.

The **QueryDirectory.InitialQuery** member is set to nonzero if **UnicodeQueryTemplate.Buffer** member of the associated FOBX is **NULL** and the **Flags** member of the FOBX does not have the FOBX\_FLAG\_MATCH\_ALL bit on.

For a wild card query ("\*.\*", for example), RDBSS will set the **UnicodeQueryTemplate.Buffer** member of the associated FOBX to the wild card query passed.

If the **PostRequest** member of the RX\_CONTEXT structure is **TRUE** on return from *MRxQueryDirectory*, then RDBSS will call [**RxFsdPostRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxfsdpostrequest) passing the RX\_CONTEXT structure to a worker queue for processing by the file system process (FSP).

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Header | Mrx.h (include Mrx.h) |

## See also

[**MRxIsValidDirectory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_chkdir_calldown)

[**MRxQueryEaInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxqueryeainfo)

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

[**RxFsdPostRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxfsdpostrequest)

