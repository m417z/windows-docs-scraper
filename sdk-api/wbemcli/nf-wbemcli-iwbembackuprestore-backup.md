# IWbemBackupRestore::Backup

## Description

The **IWbemBackupRestore::Backup** method backs up the contents of the static repository to a separate file.

## Parameters

### `strBackupToFile` [in]

Constant, null-terminated string of 16-bit Unicode characters that contains the file name to which to back up the contents of the repository.

### `lFlags` [in]

Reserved. This parameter must be 0 (zero).

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.