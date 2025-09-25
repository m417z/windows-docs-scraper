# FsRtlIsDaxVolume function

## Description

This routine queries if the specified file is on a direct access (DAX) volume.

## Parameters

### `FileObject` [in]

A file object for a file, on the volume which is being queried.

## Return value

Returns **true** if the file is on a DAX volume; otherwise, **false**.

## Remarks

In DAX volumes, user files
are mapped directly to the persistent memory device. Files are
then accessed using the memory bus, to help boost system performance.