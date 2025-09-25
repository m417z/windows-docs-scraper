# RtlIsPartialPlaceholderFileHandle function

## Description

The **RtlIsPartialPlaceholderFileHandle** routine determines if a file is a known type of placeholder, based on a file
handle.

## Parameters

### `FileHandle` [in]

**FileHandle** is a handle to the placeholder file whose partial state is to be queried. The file handle must have at least **FILE_READ_ATTRIBUTES** access.

### `IsPartialPlaceholder` [out]

**IsPartialPlaceholder** is a pointer to a boolean which is **TRUE** if the file or directory is a placeholder. It returns **FALSE** if either the
file or directory is not a placeholder or is a full placeholder; undefined on failure.

## Return value

Returns **STATUS_SUCCESS** if *IsPartialPlaceholder* is valid and not undefined.

## See also

[RtlIsPartialPlaceholder](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlispartialplaceholder)