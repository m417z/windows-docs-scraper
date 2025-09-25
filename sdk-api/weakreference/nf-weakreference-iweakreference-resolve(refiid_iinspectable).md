## Description

Resolves a weak reference by returning a strong reference to the object.

## Parameters

### `riid`

Type: **REFIID**

A reference to the interface identifier (IID) of the object.

### `objectReference`

Type: **[IInspectable](https://learn.microsoft.com/windows/win32/api/inspectable/nn-inspectable-iinspectable)****

A strong reference to the object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If you try to resolve a weak reference to a strong reference for an object that is no longer available, then **IWeakReference::Resolve** returns **S_OK**, but the *objectReference* parameter points to null.

## See also

[IWeakReference](https://learn.microsoft.com/windows/win32/api/weakreference/nn-weakreference-iweakreference)