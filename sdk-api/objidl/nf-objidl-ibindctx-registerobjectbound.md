# IBindCtx::RegisterObjectBound

## Description

Registers an object with the bind context to ensure that the object remains active until the bind context is released.

## Parameters

### `punk` [in]

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface on the object that is being registered as bound.

## Return value

This method can return the standard return values E_OUTOFMEMORY and S_OK.

## Remarks

Those writing a new moniker class (through an implementation of the [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) interface) should call this method whenever the implementation activates an object. This happens most often in the course of binding a moniker, but it can also happen while retrieving a moniker's display name, parsing a display name into a moniker, or retrieving the time that an object was last modified.

**RegisterObjectBound** calls [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) to create an additional reference to the object. You must, however, still release your own copy of the pointer. Calling this method twice for the same object creates two references to that object. You can release a reference obtained through a call to this method by calling [IBindCtx::RevokeObjectBound](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ibindctx-revokeobjectbound). All references held by the bind context are released when the bind context itself is released.

Calling **RegisterObjectBound** to register an object with a bind context keeps the object active until the bind context is released. Reusing a bind context in a subsequent binding operation (either for another piece of the same composite moniker or for a different moniker) can make the subsequent binding operation more efficient because it doesn't have to reload that object. This, however, improves performance only if the subsequent binding operation requires some of the same objects as the original one, so you need to balance the possible performance improvement of reusing a bind context against the costs of keeping objects activated unnecessarily.

[IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx) does not provide a method to retrieve a pointer to an object registered using **RegisterObjectBound**. Assuming the object has registered itself with the running object table, moniker implementations can call [IRunningObjectTable::GetObject](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irunningobjecttable-getobject) to retrieve a pointer to the object.

## See also

[IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx)

[IRunningObjectTable::GetObject](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irunningobjecttable-getobject)