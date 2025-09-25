# IObjectControl::Activate

## Description

Enables a COM+ object to perform context-specific initialization whenever it is activated. This method is called by the COM+ run-time environment before any other methods are called on the object.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

Whenever a client calls a COM+ object that isn't already active, the COM+ run-time environment automatically activates the object. This is called [Just-in-Time Activation](https://learn.microsoft.com/windows/desktop/cossdk/com--just-in-time-activation). For components that support [IObjectControl](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iobjectcontrol) as an interface, COM+ invokes the object's **Activate** method before passing the client's method call on to the object.

Any context-specific initialization procedures should be implemented in the **Activate** method for objects that expose [IObjectControl](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iobjectcontrol).

For example, you can use the **Activate** method to obtain a reference to an object's context and store it in a member variable. Then the object context is available to any method that requires it, and you do not have to acquire a new one every time you want to use it. After you have a reference to the object's context, you can use the **IObjectControl** methods to check whether security is enabled, whether the object is executing in a transaction, or whether the caller is in a particular role.

If you are enabling object recycling (by implementing the [CanBePooled](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iobjectcontrol-canbepooled) method to query the object), the **Activate** method must be able to handle both newly created and recycled objects. When the **Activate** method returns, there should be no distinguishable difference between a new object and a recycled one.

COM+ expressly forbids calling into an object that exposes [IObjectControl](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iobjectcontrol) before calling the **Activate** method (when it is in its constructor). Such a call would result in an RPC_E_DISCONNECTED error. For example, if an object passes out a reference to itself while in its constructor and then the reference calls back into that object prior to the call to **Activate**, the disconnected error is returned.

You can also use the **Activate** method to obtain a reference to the object's [ISecurityProperty](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-isecurityproperty) interface and check the security ID of the object's creator before any methods are called.

## See also

[IObjectControl](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iobjectcontrol)