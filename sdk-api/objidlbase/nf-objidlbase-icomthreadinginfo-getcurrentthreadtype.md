# IComThreadingInfo::GetCurrentThreadType

## Description

Retrieves the type of thread in which the caller is executing.

## Parameters

### `pThreadType` [out]

A pointer to a [THDTYPE](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-thdtype) enumeration value that characterizes the caller's thread.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_FAIL** | The caller is not executing in an apartment. |

## See also

[IComThreadingInfo](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-icomthreadinginfo)