# IBITSExtensionSetup::GetCleanupTask

## Description

Use the
**GetCleanupTask** method to retrieve an interface pointer to the cleanup task associated with the virtual directory.

## Parameters

### `riid` [in]

Identifies the task scheduler interface to return in *ppTask*. For a list of identifiers, see the
[ITaskScheduler::Activate](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itaskscheduler-activate) method.

### `ppUnk` [out]

A pointer to the interface specified by *riid*. Use the interface to modify the properties of the task. Release *ppTask* when done.

## Return value

This method returns **S_OK** for success. Otherwise, the method returns **S_FALSE** if a task has not been created for the virtual directory.

## Remarks

When you create a virtual directory and
[enable](https://learn.microsoft.com/windows/desktop/api/bitscfg/nf-bitscfg-ibitsextensionsetup-enablebitsuploads) it for BITS uploads, BITS adds a work item in the
[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page). The work item cleans up the virtual directory once every 12 hours by deleting jobs that have not been modified within the time-out period. To specify the time-out period, set the
[BITSSessionTimeout](https://learn.microsoft.com/windows/desktop/Bits/bits-iis-extension-properties) IIS extension property.

To change the cleanup schedule, see the [BITSCleanupUseDefault](https://learn.microsoft.com/windows/desktop/Bits/bits-iis-extension-properties) BITS IIS extension property.

## See also

[IBITSExtensionSetup::EnableBITSUploads](https://learn.microsoft.com/windows/desktop/api/bitscfg/nf-bitscfg-ibitsextensionsetup-enablebitsuploads)

[IBITSExtensionSetup::GetCleanupTaskName](https://learn.microsoft.com/windows/desktop/api/bitscfg/nf-bitscfg-ibitsextensionsetup-getcleanuptaskname)