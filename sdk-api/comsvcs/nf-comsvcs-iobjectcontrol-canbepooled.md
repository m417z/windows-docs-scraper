# IObjectControl::CanBePooled

## Description

Notifies the COM+ run-time environment whether the object can be pooled for reuse when it is deactivated.

## Return value

If the object can be pooled for reuse, the return value is **TRUE**. Otherwise, it is **FALSE**.

## Remarks

When an object returns **TRUE** from the **CanBePooled** method, it indicates to the COM+ run-time environment that it can be added to an object pool after deactivation rather than being destroyed. Whenever an instance is required, one is drawn from the pool rather than created.

Returning **TRUE** from the **CanBePooled** method does not guarantee that objects will be recycled; it only gives the COM+ run-time environment permission to recycle them. Returning **FALSE** from the **CanBePooled** method guarantees that instances of a component are not recycled.

The [Activate](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iobjectcontrol-activate) method is called if a new instance is created or if a recycled instance is drawn from the pool. Similarly, the [Deactivate](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iobjectcontrol-deactivate) method is called every time the object is deactivated, whether it is being destroyed or returned to the pool for recycling.

## See also

[COM+ Object Pooling](https://learn.microsoft.com/windows/desktop/cossdk/com--object-pooling)

[How Object Pooling Works](https://learn.microsoft.com/windows/desktop/cossdk/how-object-pooling-works)

[IObjectControl](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iobjectcontrol)

[Requirements for Poolable Objects](https://learn.microsoft.com/windows/desktop/cossdk/requirements-for-poolable-objects)