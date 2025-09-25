# RtlIsPartialPlaceholderFileInfo function

## Description

The **RtlIsPartialPlaceholderFileInfo** routine determines if a file is a known type of placeholder, based on the information
returned by **NtQueryInformationFile** or **NtQueryDirectoryFile**.

## Parameters

### `InfoBuffer` [in]

Specifies a pointer to a caller-allocated buffer which contains information about the file object. If this is from a call
to **NtQueryDirectoryFile**, this may point to the first or any subsequent
subsequent entry in the buffer (found by walking the buffer).

### `InfoClass` [in]

 Specifies which File Information class to use to query InfoBuffer.

### `IsPartialPlaceholder` [out]

**IsPartialPlaceholder** is a pointer to a boolean which returns **TRUE** if the file or directory is a placeholder. It returns **FALSE** if either the
file or directory is not a placeholder or is a full placeholder. Returns undefined on failure.

## Return value

Returns **STATUS_SUCCESS** if IsPartialPlaceholder is valid and not undefined.

## Remarks

 If **InfoBuffer** is from a call
to **NtQueryDirectoryFile**, this may point to the first or any subsequent
subsequent entry in the buffer which is found by walking the buffer.

## See also

[RtlIsPartialPlaceholder](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlispartialplaceholder)