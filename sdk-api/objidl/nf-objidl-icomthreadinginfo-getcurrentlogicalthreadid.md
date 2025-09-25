# IComThreadingInfo::GetCurrentLogicalThreadId

## Description

Retrieves the GUID of the thread in which the caller is executing.

## Parameters

### `pguidLogicalThreadId` [out]

A pointer to the GUID of the caller's thread.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_FAIL** | The caller is not executing in an apartment. |

## See also

[IComThreadingInfo](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-icomthreadinginfo)