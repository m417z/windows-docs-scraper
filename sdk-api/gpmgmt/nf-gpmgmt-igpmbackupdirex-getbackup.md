# IGPMBackupDirEx::GetBackup

## Description

Retrieves the **GPMBackup** or **GPMStarterGPOBackup** object with the specified backup ID. The backup ID is a GUID. The backup ID is the ID of the backed-up Group Policy object (GPO), not the ID of the GPO.

## Parameters

### `bstrID` [in]

ID of the [GPMBackup](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackup) or **GPMStarterGPOBackup** object to open.

### `pvarBackup` [out]

Pointer to the
[IGPMBackup](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackup) or **IGPMStarterGPOBackup** interface for the ID specified.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns a reference to a [GPMBackup](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackup) or **GPMStarterGPOBackup** object.

### VB

Returns a reference to a [GPMBackup](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackup) or **GPMStarterGPOBackup** object.

## See also

[IGPMBackup](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackup)

[IGPMBackupCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackupcollection)

[IGPMBackupDirEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackupdirex)

**IGPMStarterGPOBackup**

**IGPMStarterGPOBackupCollection**