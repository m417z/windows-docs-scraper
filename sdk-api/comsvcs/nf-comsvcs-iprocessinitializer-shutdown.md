# IProcessInitializer::Shutdown

## Description

Called when Dllhost.exe shuts down.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

The Shutdown method is not called during a failfast or other catastrophic shutdown events.

## See also

[IProcessInitializer](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iprocessinitializer)