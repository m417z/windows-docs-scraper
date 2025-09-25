# IBITSExtensionSetup::GetCleanupTaskName

## Description

Use the
**GetCleanupTaskName** method to retrieve the name of the cleanup task associated with the virtual directory.

## Parameters

### `pTaskName` [out]

Null-terminated string containing the name of the cleanup task associated with the virtual directory. If **NULL**, BITS has not created a cleanup task for the virtual directory. When done, call the **SysFreeString** function to free *pTaskName*.

## Return value

This method returns **S_OK** for success. Otherwise, the method returns **S_FALSE** if a task name has not been specified for the virtual directory.

## Remarks

When you create a virtual directory and
[enable](https://learn.microsoft.com/windows/desktop/api/bitscfg/nf-bitscfg-ibitsextensionsetup-enablebitsuploads) it for BITS uploads, BITS adds a work item in the
[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page). The work item cleans up the virtual directory once every 12 hours by deleting jobs that have not been modified within the time-out period. To specify the time-out period, set the
[BITSSessionTimeout](https://learn.microsoft.com/windows/desktop/Bits/bits-iis-extension-properties) IIS extension property.

Use the *pTaskName* name as an input parameter to the Schtasks.exe executable file, which you can use to change the properties of the cleanup task from a script.

## See also

[IBITSExtensionSetup::EnableBITSUploads](https://learn.microsoft.com/windows/desktop/api/bitscfg/nf-bitscfg-ibitsextensionsetup-enablebitsuploads)

[IBITSExtensionSetup::GetCleanupTask](https://learn.microsoft.com/windows/desktop/api/bitscfg/nf-bitscfg-ibitsextensionsetup-getcleanuptask)