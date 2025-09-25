# FsRtlOplockIsSharedRequest function

## Description

The **FsRtlOplockIsSharedRequest** routine determines if a request for an opportunistic lock (oplock) wants a shared oplock.

## Parameters

### `Irp` [in]

A pointer to the IRP that declares the requested operation. The caller must ensure that the IRP has a major code of IRP_MJ_FILE_SYSTEM_CONTROL and a minor code of IRP_MN_USER_FS_REQUEST.

## Return value

**FsRtlOplockIsSharedRequest** returns **TRUE** if the oplock request is for a shared oplock (that is, a level 2, R, or RH oplock). **FsRtlOplockIsSharedRequest** returns **FALSE** if the oplock request is not for a shared oplock or if the IRP is not an oplock request. For more information about oplock types, see the Oplock Semantics [Overview](https://learn.microsoft.com/windows-hardware/drivers/image/overview) page. Minifilters should call [FltOplockIsSharedRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltoplockissharedrequest) instead of **FsRtlOplockIsSharedRequest**.

## See also

[FltOplockIsSharedRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltoplockissharedrequest)