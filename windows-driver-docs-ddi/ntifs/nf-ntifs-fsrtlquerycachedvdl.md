# FsRtlQueryCachedVdl function

## Description

The current valid data length (VDL) for a cached file is retrieved with the **FsRtlQueryCachedVdl** routine.

## Parameters

### `FileObject` [in]

The file object to retrieve the cached VDL for.

### `Vdl` [out]

 A pointer to a caller supplied value which receives the VDL.

## Return value

**FsRtlQueryCachedVdl** returns **STATUS_SUCCESS** if the cached VDL is obtained successfully for the *FileObject* specified. Otherwise, another appropriate **NTSTATUS** value is returned.

## Remarks

The **FsRtlQueryCachedVdl** routine will return the VDL for a full span file region. This is a region beginning at an offset of 0 and having a length of **MAXLONGLONG**.