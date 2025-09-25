# IGPM::GetBackupDir

## Description

Creates and returns a [GPMBackupDir](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackupdir) object, which you can use to access
the [GPMBackup](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackup) and
[GPMBackupCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackupcollection) objects.

## Parameters

### `bstrBackupDir` [in]

Required. The name of the file system directory that contains the Group Policy object (GPO) backups. The directory must already exist.

### `pIGPMBackupDir` [out]

Address of a pointer to the
[IGPMBackupDir](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackupdir) interface.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs

### JScript

Returns a reference to a **GPMBackupDir** object.

### VB

Returns a reference to a **GPMBackupDir** object.

## See also

[IGPM](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpm)

[IGPMBackup](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackup)

[IGPMBackupCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackupcollection)

[IGPMBackupDir](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackupdir)