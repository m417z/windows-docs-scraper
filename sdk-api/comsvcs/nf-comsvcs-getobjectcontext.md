# GetObjectContext macro

## Description

Retrieves a reference to the context that is associated with the current COM+ object.

For similar functionality, see [IMTxAS::GetObjectContext](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683405(v=vs.85)).

## Parameters

### `ppIOC` [out]

A reference to [IObjectContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iobjectcontext) on the object's context. If the object's component has not been imported into an MTS package or if the **GetObjectContext** function is called from a constructor or an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) method, this parameter is set to a **NULL** pointer.

## Remarks

An object's context is not accessible from an object's constructor or from any [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) method.

An object should never attempt to pass its [IObjectContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iobjectcontext) reference to another object. If you pass an **IObjectContext** reference to another object, it is no longer a valid reference.

When an object obtains a reference to its [IObjectContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iobjectcontext), it must release the **IObjectContext** object when it is finished with it.

## See also

[COM+ Contexts and Threading Models](https://learn.microsoft.com/windows/desktop/cossdk/com--contexts-and-threading-models)

[IMTxAS::GetObjectContext](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683405(v=vs.85))

[IObjectContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iobjectcontext)