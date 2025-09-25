# IoIsFileObjectIgnoringSharing function

## Description

The **IoIsFileObjectIgnoringSharing** routine determines if a file object is set with the option to ignore file sharing access checks.

## Parameters

### `FileObject`

Pointer to a file object for the file.

## Return value

**TRUE** if file sharing access checks are ignored. Otherwise, **FALSE**.

## See also

[IoSetFileObjectIgnoreSharing](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iosetfileobjectignoresharing)