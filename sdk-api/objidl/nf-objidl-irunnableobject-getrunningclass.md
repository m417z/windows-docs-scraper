# IRunnableObject::GetRunningClass

## Description

Retrieves the CLSID of a running object.

## Parameters

### `lpClsid` [out]

A pointer to the object's class identifier.

## Return value

This method can return the standard return values E_INVALIDARG, E_UNEXPECTED, and S_OK.

## Remarks

If an embedded document was created by an application that is not available on the user's computer, the document, by a call to [CoTreatAsClass](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-cotreatasclass), may be able to display itself for editing by emulating a class that is supported on the user's machine. In this case, the CLSID returned by a call to **IRunnableObject::GetRunningClass** will be that of the class being emulated, rather than the document's native class.

## See also

[IRunnableObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irunnableobject)