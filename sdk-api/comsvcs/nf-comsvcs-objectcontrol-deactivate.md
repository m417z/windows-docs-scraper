# ObjectControl::Deactivate

## Description

Enables a COM+ object to perform cleanup required before it is recycled or destroyed.

This method is called by the COM+ run-time environment whenever an object is deactivated. Do not make any method calls on objects in the same activity from this method.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

The COM+ run-time environment calls the **Deactivate** method whenever an object that supports the [ObjectControl](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-objectcontrol) interface is deactivated. An object is deactivated when it returns from a method in which the method called [SetComplete](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-objectcontext-setcomplete) or [SetAbort](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-objectcontext-setabort), when the transaction in which it executed is committed or aborted, or when the last client to hold a reference on the object releases its reference.

If the component supports recycling (returns **TRUE** from the [CanBePooled](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-objectcontrol-canbepooled) method), you must use the **Deactivate** method to reset the object's state to the state in which the [Activate](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-objectcontrol-activate) method expects to find it. You can also use the **Deactivate** method to release the object's context or to do other context-specific cleanup. Even if an object supports recycling, it can be beneficial to release certain reusable resources in its **Deactivate** method. For example, ODBC provides its own connection pooling. It is more efficient to pool a database connection in a general connection pool where other objects can use it than it is to keep it tied to a specific object in an object pool.

COM+ expressly forbids calling into an object that exposes [ObjectControl](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-objectcontrol) after the **Deactivate** method has returned (when it is in its destructor). Such a call would result in an RPC_E_DISCONNECTED error. For example, if an object has passed out a reference to itself and then calls back into the object after **Deactivate** has returned, a disconnected error results.

## See also

[ObjectControl](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-objectcontrol)