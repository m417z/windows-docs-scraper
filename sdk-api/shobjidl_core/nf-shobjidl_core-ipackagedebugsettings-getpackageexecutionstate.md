# IPackageDebugSettings::GetPackageExecutionState

## Description

Returns the current execution state of the specified package.

## Parameters

### `packageFullName` [in]

Type: **LPCWSTR**

The package full name.

### `packageExecutionState` [out]

Type: **[PACKAGE_EXECUTION_STATE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-package_execution_state)***

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Debuggers can use the **GetPackageExecutionState** to understand if the application currently is running, suspending, suspended, or terminated. The **GetPackageExecutionState** function doesn't provide the state of background tasks running in the package.

## See also

[IPackageDebugSettings](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ipackagedebugsettings)