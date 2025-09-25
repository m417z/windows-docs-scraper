# FSRTL_ADVANCED_FCB_HEADER::FsRtlOplockGetAnyBreakOwnerProcess

## Description

**FsRtlOplockGetAnyBreakOwnerProcess** returns an owner of an allegedly breaking opportunistic lock (oplock).

## Parameters

### `Oplock`

Pointer to the opaque oplock structure for the file. This pointer must have been initialized by a previous call to [**FsRtlInitializeOplock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializeoplock).

## Return value

This method returns **NULL** if no owner can be found; otherwise it returns a pointer to an owner's process object (PEPROCESS).

## Remarks

**FsRtlOplockGetAnyBreakOwnerProcess** selects an owner for the allegedly breaking oplock as follows:

- If the oplock has an exclusive owner, **FsRtlOplockGetAnyBreakOwnerProcess** returns a pointer to the exclusive owner's EPROCESS.

- If the oplock does not have an exclusive owner and the break queue is non-empty, **FsRtlOplockGetAnyBreakOwnerProcess** arbitrarily returns a pointer to the first EPROCESS in the queue.

- Otherwise, **FsRtlOplockGetAnyBreakOwnerProcess** returns NULL.

If **FsRtlOplockGetAnyBreakOwnerProcess** returns non-NULL, the caller is responsible for calling [**ObDeferenceObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject) to release the reference acquired on its behalf.

**FsRtlOplockGetAnyBreakOwnerProcess** does not attempt to verify that a break is actually pending, or that the process it returns is indeed the owner.

## See also

[**FsRtlInitializeOplock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializeoplock)

[**ObDeferenceObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject)