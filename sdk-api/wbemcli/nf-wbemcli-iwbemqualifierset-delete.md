# IWbemQualifierSet::Delete

## Description

The **IWbemQualifierSet::Delete** method deletes the specified qualifier by name. Due to qualifier propagation rules, a particular qualifier may have been inherited from another object and merely overridden in the current class or instance. In this case, use the
**Delete** method to reset the qualifier to the original inherited value.

## Parameters

### `wszName` [in]

Name of the qualifier to delete. The pointer is treated as read-only.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

## See also

[Qualifier Flavors](https://learn.microsoft.com/windows/desktop/WmiSdk/qualifier-flavors)