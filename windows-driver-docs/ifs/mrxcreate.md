# MRxCreate routine

The*MRxCreate* routine is called by [RDBSS](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-rdbss-driver-and-library) to request that the network mini-redirector create a file system object.

## Parameters

*RxContext* \[in, out\]
A pointer to the RX\_CONTEXT structure. This parameter contains the IRP that is requesting the operation.

## Return value

*MRxCreate* returns STATUS\_SUCCESS on success or an appropriate NTSTATUS value, such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | There were insufficient resources to complete the operation. |
| **STATUS_NETWORK_ACCESS_DENIED** | Network access was denied. This error can be returned if the network mini-redirector was asked to open a new file on a read-only share. |
| **STATUS_NOT_IMPLEMENTED** | A feature that is requested, such as remote boot or a remote page file, is not implemented. |
| **STATUS_NOT_SUPPORTED** | A feature that is requested, such as extended attributes, is not supported. |
| **STATUS_OBJECT_NAME_COLLISION** | The network mini-redirector was asked to create a file that already exists. |
| **STATUS_OBJECT_NAME_NOT_FOUND** | The object name was not found. This error can be returned if the network mini-redirector was asked to open a file that doesn't exist. |
| **STATUS_OBJECT_PATH_NOT_FOUND** | The object path was not found. This error can be returned if an NTFS stream object was requested and the remote file system does not support streams. |
| **STATUS_REPARSE** | A reparse is required to handle a symbolic link. |
| **STATUS_RETRY** | The operation should be retried. This error can be returned if the network mini-redirector encountered a sharing violation or an access denied error. |

## Remarks

*MRxCreate* is called by RDBSS to request that the network mini-redirector open a file system object across the network. This call is issued by RDBSS in response to receiving an [**IRP\_MJ\_CREATE**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create) request.

Before calling *MRxCreate*, RDBSS modifies the following members in the RX\_CONTEXT structure pointed to by the *RxContext* parameter:

**pRelevantSrvOpen** is set to the SRV\_OPEN structure.

**Create.pSrvCall** is set to the SRV\_CALL structure.

**Create.NtCreateParameters** is set to the requested NT\_CREATE\_PARAMETERS.

In the context of a network mini-redirector, a file object refers to the associated file control block (FCB) and file object extension (FOBX) structures. There is a one to one correspondence between file objects and FOBXs. Many file objects will refer to the same FCB, which represents a single file on a remote server. A client can have several different open requests (NtCreateFile requests) on the same FCB and each of these will create a new file object. RDBSS and network mini-redirectors can choose to send fewer *MRxCreate* requests than the NtCreateFile requests received, in effect sharing an SRV\_OPEN structure among several FOBXs.

If the *MRxCreate* request was for a file overwrite and *MRxCreate* returned STATUS\_SUCCESS, then RDBSS will acquire the paging I/O resource and truncate the file. If the file is being cached by cache manager, RDBSS will update the sizes the cache manager has with the ones just received from the server.

Before returning, *MRxCreate* must set the **CurrentIrp->IoStatus.Information** member of the RX\_CONTEXT structure pointed to by the *RxContext* parameter.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Header | Mrx.h (include Mrx.h) |

## See also

[**MRxAreFilesAliased**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_chkfcb_calldown)

[**MRxCleanupFobx**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549841(v=vs.85))

[**MRxCloseSrvOpen**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_calldown)

[**MRxCollapseOpen**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxcollapseopen)

[**MRxCreate**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxcreate)

[**MRxDeallocateForFcb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_deallocate_for_fcb)

[**MRxDeallocateForFobx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_deallocate_for_fobx)

[**MRxExtendForCache**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_extendfile_calldown)

[**MRxExtendForNonCache**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxextendfornoncache)

[**MRxFlush**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxflush)

[**MRxForceClosed**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_forceclosed_calldown)

[**MRxIsLockRealizable**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_is_lock_realizable)

[**MRxShouldTryToCollapseThisOpen**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxshouldtrytocollapsethisopen)

[**MRxTruncate**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxtruncate)

[**MRxZeroExtend**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxzeroextend)

