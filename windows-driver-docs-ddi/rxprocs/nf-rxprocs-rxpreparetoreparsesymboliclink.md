# RxPrepareToReparseSymbolicLink function

## Description

**RxPrepareToReparseSymbolicLink** sets up the file object name to facilitate a reparse. This routine is used by the network mini-redirectors to traverse symbolic links.

## Parameters

### `RxContext`

A pointer to the RX_CONTEXT structure.

### `SymbolicLinkEmbeddedInOldPath`

A Boolean value that indicates that a symbolic link was encountered. If the value is **TRUE**, a symbolic link was encountered as part of the traversal of the old path.

### `NewPath`

A pointer to a Unicode string that contains the new path name to be traversed.

### `NewPathIsAbsolute`

A Boolean value that indicates if the new path is absolute. If this value is **FALSE**, \Device\Mup should be prepended to *NewPath*. If this value is **TRUE**, the *NewPath* parameter is the full path to reparse. In this case, the buffer that contains *NewPath* is used directly, rather than allocating a new buffer.

### `ReparseRequired`

A pointer to a Boolean value that indicates whether a reparse is required. If this value is **TRUE**, a reparse is required.

## Return value

**RxPrepareToReparseSymbolicLink** returns STATUS_SUCCESS on success or one of the following error values on failure:

| Return code | Description |
| --- | --- |
| **STATUS_ACCESS_DENIED** | A request to delete failed. |
| **STATUS_INSUFFICIENT_RESOURCES** | There were insufficient resources available. |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was passed to the routine. This error will be returned if the **MajorFunction** member of *RxContext* is not IRP_MJ_CREATE. |

## Remarks

The **RxPrepareToReparseSymbolicLink** routine would only be used by a network mini-redirector that supports symbolic links and uses reparse points to implement symbolic links. The **RxPrepareToReparseSymbolicLink** routine would normally be called by a network mini-redirector from its **MrxCreate** callback routine.

The *SymbolicLinkEmbeddedInOldPath* parameter passed to this routine is very important. To preserve the correct semantics, it should be carefully used. For example, consider the old path \A\B\C\D where C happens to be a symbolic link. In this case, the symbolic link is embedded in the path and *SymbolicLinkEmbeddedInOldPath* should be set to **TRUE**. In contrast, this is very different from the case when D happens to be a symbolic link. In the former case, the reparse constitutes an intermediate step. In the second example, the reparse constitutes the final step of the name resolution and *SymbolicLinkEmbeddedInOldPath* should be set to **FALSE**.

If DELETE access is specified, the open or create operation is denied for all cases in which the symbolic link is not embedded. It is possible that if DELETE access were the only one specified, then the open attempt must succeed without reparse. This conforms UNIX symbolic link semantics.

As part of this routine, *RxContext* is also tagged appropriately. This ensures that the return value can be crosschecked with the invocation of this routine. Once **RxPrepareToReparseSymbolicLink** is invoked, the network mini redirector has to return STATUS_REPARSE.

The value of the *ReparseRequired* parameter assumes significance only if STATUS_SUCCESS is returned from this routine. If *ReparseRequired* is **FALSE**, this implies that no reparse attempt is required and the symbolic link file itself should be manipulated as opposed to the target of the link. If *ReparseRequired* is **TRUE**, this implies that a reparse attempt was successfully setup. In such cases, it is imperative that the network mini redirector returns STATUS_REPARSE for the associated **MRxCreate** call. RDBSS will initiate a check for this condition.

## See also

[MRxCreate](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxcreate)