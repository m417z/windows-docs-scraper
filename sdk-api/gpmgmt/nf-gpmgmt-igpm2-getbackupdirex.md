# IGPM2::GetBackupDirEx

## Description

For a Group Policy object (GPO), the **GetBackupDirEx** method creates and returns a [GPMBackupDirEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackupdir) object, which you can use to access
a [GPMBackup](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackup) or [GPMBackupCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackupcollection) object.

For a Starter Group Policy object, the **GetBackupDirEx** method creates and returns a [GPMBackupDirEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackupdir) object, which you can use to access
a [GPMStarterGPOBackup](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstartergpobackup) or [GPMStarterGPOBackupCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstartergpobackupcollection) object.

## Parameters

### `bstrBackupDir` [in]

Required. The name of the file system directory containing the Group Policy object (GPO) backups. Note that the directory must already exist.

### `backupDirType` [in]

Determines whether the back up is for a Starter Group Policy object or a Group Policy object.

### `ppIGPMBackupDirEx` [out, retval]

Address of a pointer to the [IGPMBackupDirEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackupdirex) interface.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns a reference to a [GPMBackupDirEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackupdirex) object.

### VB

Returns a reference to a [GPMBackupDirEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackupdirex) object.

## See also

[IGPM](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpm)

[IGPM2](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpm2)

[IGPMBackup](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackup)

[IGPMBackupCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackupcollection)

[IGPMBackupDir](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackupdir)

[IGPMStarterGPOBackup](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstartergpobackup)

[IGPMStarterGPOBackupCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstartergpobackupcollection)