# INetFwRules::Remove

## Description

The **Remove** method removes a rule from the collection.

## Parameters

### `name` [in]

Name of the rule to remove from the collection.

## Return value

### C++

If the method succeeds the return value is S_OK.

If the method fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | The operation was aborted due to permissions issues. |
| **E_INVALIDARG** | The method failed due to an invalid parameter. |
| **E_OUTOFMEMORY** | The method was unable to allocate required memory. |

### VB

If the method succeeds the return value is S_OK.

If the method fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | The operation was aborted due to permissions issues. |
| **E_INVALIDARG** | The method failed due to an invalid parameter. |
| **E_OUTOFMEMORY** | The method was unable to allocate required memory. |

## Remarks

If a rule specified by the *name* parameter does not exist in the collection, the **Remove** method has no effect.

## See also

[INetFwRules](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwrules)