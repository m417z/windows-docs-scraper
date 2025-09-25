# IPackageDebugSettings::TerminateAllProcesses

## Description

Terminates all processes for the specified package.

## Parameters

### `packageFullName` [in]

The package full name.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method does not suspend the processes first. To test suspension followed by termination, call the [Suspend](https://learn.microsoft.com/windows/desktop/WinRT/ipackagedebugsettings-suspend) method before calling [TerminateAllProcesses](https://learn.microsoft.com/previous-versions/hh438399(v=vs.85)).

## See also

[IPackageDebugSettings](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ipackagedebugsettings)