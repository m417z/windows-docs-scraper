# IGetVBAObject::GetObject

## Description

Gets a pointer to an interface on the VBA object.

**Note** The use of this method is no longer recommended because containers other than Visual Basic do not support
it.

## Parameters

### `riid` [in]

Specifies the interface to retrieve. Pass **IID_IVBFormat** to retrieve a pointer to
the [IVBFormat](https://learn.microsoft.com/windows/desktop/api/vbinterf/nn-vbinterf-ivbformat) interface.

### `ppvObj` [out]

Pointer to the interface.

### `dwReserved` [in]

Reserved.

## Return value

This method supports the standard return values **E_INVALIDARG**,
**E_OUTOFMEMORY**, and **E_UNEXPECTED**, as well as the
following:

## See also

[IGetVBAObject](https://learn.microsoft.com/windows/desktop/api/vbinterf/nn-vbinterf-igetvbaobject)