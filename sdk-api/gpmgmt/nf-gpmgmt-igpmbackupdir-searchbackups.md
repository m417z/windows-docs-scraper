# IGPMBackupDir::SearchBackups

## Description

Executes a search for
the [GPMBackup](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackup) object according to the specified criteria, and returns an
[GPMBackupCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackupcollection) object.

## Parameters

### `pIGPMSearchCriteria` [in]

Pointer to the criteria to apply to the search.

#### gpoDomain

Pointer to the criteria for a search for a domain name. The search property value is the domain name. The **opEquals** or **opNotEquals** operators are valid search criteria.

#### gpoID

Pointer to criteria for a search for a Group Policy object (GPO) ID. The search property value is the GPO ID. The **opEquals** or **opNotEquals** operators are valid search criteria.

#### gpoDisplayName

Pointer to criteria for a search for a GPO display name. The search property value is the GPO display name. The **opEquals**, **opContains**, or **opNotContains** operators are valid search criteria.

#### backupMostRecent

Pointer to criteria for a search for the most recent backup. The search property value is **TRUE**. The **opEquals** operator is the valid search criteria.

### `ppIGPMBackupCollection` [out]

Address of a pointer to the
[IGPMBackupCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackupcollection) interface that represents the [IGPMBackup](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackup) objects found by the search.

#### - objGPMSearchCriteria [in]

[GPMSearchCriteria](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsearchcriteria) object to apply to the search.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns a reference to a **GPMBackupCollection** object.

### VB

Returns a reference to a **GPMBackupCollection** object.

## Remarks

An empty [GPMSearchCriteria](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsearchcriteria) has had no criteria added to it. Passing in an empty **GPMSearchCriteria** will return all
[GPMBackup](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackup) objects.

## See also

[IGPMBackup](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackup)

[IGPMBackupCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackupcollection)

[IGPMBackupDir](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackupdir)