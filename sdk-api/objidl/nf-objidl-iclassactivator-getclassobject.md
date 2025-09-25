# IClassActivator::GetClassObject

## Description

Retrieves a class object.

## Parameters

### `rclsid` [in]

The CLSID that identifies the class whose class object is to be retrieved.

### `dwClassContext` [in]

The context in which the class is expected to run. For a list of values, see the [CLSCTX](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ne-wtypesbase-clsctx) enumeration.

### `locale` [in]

An LCID constant as defined in WinNls.h.

### `riid` [in]

The IID of the interface on the object to which a pointer is desired.

### `ppv` [out]

The address of pointer variable that receives the interface pointer requested in *riid*. Upon successful return, **ppv* contains the requested interface pointer.

## Return value

If the method succeeds, the return value is S_OK. Otherwise, it is E_FAIL.

## See also

[CoGetClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetclassobject)

[IClassActivator](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iclassactivator)