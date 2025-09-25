# FltOplockIsSharedRequest function

## Description

The **FltOplockIsSharedRequest** routine determines if a request for an opportunistic lock (oplock) wants a shared oplock.

## Parameters

### `CallbackData` [in]

A pointer to the callback data ([FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) structure for the I/O operation. The caller must ensure that the I/O operation has a major code of IRP_MJ_FILE_SYSTEM_CONTROL and a minor code of IRP_MN_USER_FS_REQUEST.

## Return value

**FltOplockIsSharedRequest** returns **TRUE** if the oplock request is for a shared oplock (that is, a level 2, R, or RH oplock). **FltOplockIsSharedRequest** returns **FALSE** if the oplock request is not for a shared oplock or if the I/O operation is not an oplock request. For more information about oplock types, see [Oplock Semantics Overview](https://learn.microsoft.com/windows-hardware/drivers/image/overview).

## See also

[FsRtlOplockIsSharedRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtloplockissharedrequest)