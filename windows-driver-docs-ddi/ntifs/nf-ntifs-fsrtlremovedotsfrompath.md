# FsRtlRemoveDotsFromPath function

## Description

The **FsRtlRemoveDotsFromPath** routine removes unnecessary occurrences of '.' and '..' from the specified path.

## Parameters

### `OriginalString` [in, out]

A pointer to the buffer to be processed.

### `PathLength` [in]

The length of buffer (in bytes).

### `NewLength` [out]

A pointer to the new length of the buffer, after processing.

## Return value

The **FsRtlRemoveDotsFromPath** routine returns either STATUS_SUCCESS value for success or STATUS_IO_REPARSE_DATA_INVALID if the operation could not be completed.

## Remarks

This routine would take a path as *OriginalString* like the following example:

```
\dir1\dir2\..\dir3\.\file.txt
```

The routine would modify *OriginalString* as follows:

```
\dir1\dir3\file.txt
```

The routine will fail with STATUS_IO_REPARSE_DATA_INVALID if any of the following strings are passed as *OriginalString*:

```
\..
..
..\anyOtherContent
```