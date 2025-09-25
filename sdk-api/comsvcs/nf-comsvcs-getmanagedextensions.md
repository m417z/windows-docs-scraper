# GetManagedExtensions function

## Description

Determines whether the installed version of COM+ supports special features provided to manage serviced components (managed objects).

## Parameters

### `dwExts` [out]

Indicates whether the installed version of COM+ supports managed extensions. A value of 1 indicates that it does, while a value of 0 indicates that it does not.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

Several COM+ services, such as [COM+ Just-in-Time Activation](https://learn.microsoft.com/windows/desktop/cossdk/com--just-in-time-activation) and [COM+ Events](https://learn.microsoft.com/windows/desktop/cossdk/com--events), support the [IManagedActivationEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-imanagedactivationevents) interface. This interface provides additional code for managing serviced components (managed objects). To take advantage of this additional code, the serviced component must support the [IManagedObjectInfo](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-imanagedobjectinfo) interface. The **GetManagedExtensions** function allows you to determine the availability of this additional code in the installed version of COM+.

## See also

[IManagedActivationEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-imanagedactivationevents)

[IManagedObjectInfo](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-imanagedobjectinfo)

[IManagedPooledObj](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-imanagedpooledobj)