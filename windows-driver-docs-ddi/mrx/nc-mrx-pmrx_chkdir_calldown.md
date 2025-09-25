# PMRX_CHKDIR_CALLDOWN callback function

## Description

The**MRxIsValidDirectory** routine is called by [RDBSS](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-rdbss-driver-and-library) to request that a network mini-redirector check for the existence of a remote directory.

## Parameters

### `RxContext` [in, out]

A pointer to the RX_CONTEXT structure. This parameter contains the IRP that is requesting the operation.

### `DirectoryName` [in]

A pointer to a Unicode string that contains the name of the remote directory.

## Return value

**MRxIsValidDirectory** returns STATUS_SUCCESS on success or an appropriate NTSTATUS value, such as the following:

| Return code | Description |
| ------------- | ------------- |
| STATUS_BAD_NETWORK_PATH | This remote directory does not exist. |

## Remarks

**MRxIsValidDirectory** is called as part of create or open request processing for the remaining name string beyond the V_NET_ROOT structure, if the **IrpSp->Parameters.Create.Options** member has the FILE_CREATE_TREE_CONNECTION bit set on.

## See also

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

[**MRxSetSdInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetsdinfo)

[**MRxSetVolumeInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetvolumeinfo)