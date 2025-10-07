# MRxSetFileInfoAtCleanup routine

The *MRxSetFileInfoAtCleanup* routine is called by [RDBSS](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-rdbss-driver-and-library) to request that a network mini-redirector set file information on a file system object at cleanup.

## Parameters

*RxContext* \[in, out\]
A pointer to the RX\_CONTEXT structure. This parameter contains the IRP that is requesting the operation.

## Return value

*MRxSetFileInfoAtCleanup* returns STATUS\_SUCCESS on success or an appropriate NTSTATUS value.

## Remarks

RDBSS issues a call to *MRxSetFileInfoAtCleanup* during cleanup, when the last handle to a file object is closed. This is different than the close operation which is invoked when the last reference to a file object is deleted.

*MRxSetFileInfoAtCleanup* is called by RDBSS if the timestamps on a file or the size of a file have changed. The calls to *MRxSetFileInfoAtCleanup* by RDBSS are made separately for each of these changes. If both the file size and the timestamps have changed, then RDBSS makes two calls to *MRxSetFileInfoAtCleanup*.

Before calling *MRxSetFileInfoAtCleanup*, RDBSS modifies the following members in the RX\_CONTEXT structure pointed to by the *RxContext* parameter if the timestamps on a file have changed:

The **Info.FileInformationClass** member is set to a FILE\_INFORMATION\_CLASS value of FileBasicInformation.

The **Info.Buffer** member is set to a FILE\_BASIC\_INFORMATION structure allocated on the stack.

The **Info.Length** member is set to the sizeof a FILE\_BASIC\_INFORMATION structure.

Before calling *MRxSetFileInfoAtCleanup*, RDBSS modifies the following members in the RX\_CONTEXT structure pointed to by the *RxContext* parameter if the size of a file has changed:

The **Info.FileInformationClass** member is set to a FILE\_INFORMATION\_CLASS value of FileEndOfFileInformation.

The **Info.Buffer** member is set to a FILE\_END\_OF\_FILE\_INFORMATION structure allocated on the stack.

The **Info.Length** member is set to **sizeof(**FILE\_END\_OF\_FILE\_INFORMATION**)**.

RDBSS ignores the return value from *MRxSetFileInfoAtCleanup*.

A network mini-redirector can choose to do nothing in this routine and return STATUS\_SUCCESS. Any changes to the file size or timestamps will be handled during the cleanup operation.

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

[**MRxSetQuotaInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetquotainfo)

[**MRxSetSdInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetsdinfo)

[**MRxSetVolumeInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetvolumeinfo)

