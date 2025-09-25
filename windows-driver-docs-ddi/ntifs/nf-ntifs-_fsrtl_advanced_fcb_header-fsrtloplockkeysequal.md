# FsRtlOplockKeysEqual function

## Description

The **FsRtlOplockKeysEqual** routine compares the opportunistic lock (oplock) keys that are stored in the file object extensions of two file objects.

## Parameters

### `Fo1` [in, optional]

A pointer to the first file object for the comparison.

### `Fo2` [in, optional]

A pointer to the second file object for the comparison.

## Return value

The **FsRtlOplockKeysEqual** routine returns **TRUE** if the keys match or if the file object pointers are the same. **FsRtlOplockKeysEqual** returns **FALSE** if the keys do not match, if either of the file objects is missing, or if either of the file objects does not have a key.

## Remarks

If no oplock keys were provided when the file objects were created, they are considered to match if the file object pointers are the same (that is, they are the same file object). If the file object pointers are different and either or both of them do not have an associated oplock key, they are considered to not match.

Minifilters should call [FltOplockKeysEqual](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltoplockkeysequal) instead of **FsRtlOplockKeysEqual**.

## See also

[FltOplockKeysEqual](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltoplockkeysequal)