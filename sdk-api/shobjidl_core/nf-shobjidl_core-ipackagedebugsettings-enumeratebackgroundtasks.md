# IPackageDebugSettings::EnumerateBackgroundTasks

## Description

Gets the background tasks that are provided by the specified package.

## Parameters

### `packageFullName` [in]

The package full name to query for background tasks.

### `taskCount` [out]

The count of *taskIds* and *taskNames* entries.

### `taskIds` [out]

An array of background task identifiers. You can use these identifiers in the [ActivateBackgroundTask](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipackagedebugsettings-activatebackgroundtask) method to activate specified tasks.

### `taskNames` [out]

An array of task names that corresponds with background *taskIds*.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Both parameters *taskIds* and *taskNames* have the same ordering of tasks. If you need to know the user-readable task name associated with *taskId[0]*, refer to *taskNames[0]*.

## See also

[IPackageDebugSettings](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ipackagedebugsettings)