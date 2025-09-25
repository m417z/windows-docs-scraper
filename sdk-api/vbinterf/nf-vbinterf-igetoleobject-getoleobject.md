# IGetOleObject::GetOleObject

## Description

Gets a pointer to an OLE control on a Visual Basic container.

**Note** The use of this method is no longer recommended because containers other than Visual Basic do not support
it.

## Parameters

### `riid` [in]

Specifies the interface to retrieve. Pass **IID_IOleObject** to obtain a pointer to
the control.

### `ppvObj` [out]

Pointer to the control.

## Return value

This method supports the standard return values **E_INVALIDARG**,
**E_OUTOFMEMORY**, and **E_UNEXPECTED**, as well as the
following:

## See also

[IGetOleObject](https://learn.microsoft.com/windows/desktop/api/vbinterf/nn-vbinterf-igetoleobject)