## Description

Executes a search for a [GPMBackup](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackup) object or an **IGPMStarterGPOBackup** interface according to the specified criteria, and returns a
[GPMBackupCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackupcollection) or **GPMStarterGPOBackupCollection** object.

## Parameters

### `pIGPMSearchCriteria` [in]

Pointer to the criteria to be applied to the search.

### `pvarBackupCollection` [out]

Pointer to the
[IGPMBackupCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackupcollection) or [IGPMStarterGPOBackupCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackupcollection) interface that represent the [IGPMBackup](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackup) or **IGPMStarterGPOBackup** objects that are found by the search.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns a reference to a **GPMBackupCollection** or **GPMStarterGPOBackupCollection** object.

### VB

Returns a reference to a **GPMBackupCollection** or **GPMStarterGPOBackupCollection** object.

## Remarks

An empty [IGPMSearchCriteria](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsearchcriteria) interface or **GPMSearchCriteria** object has had no criteria added to it. Passing in an empty **IGPMSearchCriteria** interface or **GPMSearchCriteria** object will return all
information in the [IGPMBackup](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackup) or **IGPMStarterGPOBackup** interface.

## See also

[IGPMBackup](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackup)

[IGPMBackupCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackupcollection)

[IGPMBackupDirEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackupdirex)

**IGPMStarterGPOBackup**

**IGPMStarterGPOBackupCollection**