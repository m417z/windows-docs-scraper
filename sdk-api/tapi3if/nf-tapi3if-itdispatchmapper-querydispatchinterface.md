# ITDispatchMapper::QueryDispatchInterface

## Description

The
**QueryDispatchInterface** method returns a dispatch pointer to a different interface on an object given its GUID and the dispatch pointer of another interface on the object.

## Parameters

### `pIID` [in]

Pointer to **BSTR** representation of GUID for needed interface.

### `pInterfaceToMap` [in]

**IDispatch** pointer of starting interface.

### `ppReturnedInterface` [out]

**IDispatch** pointer of interface corresponding the GUID contained in *pIID*.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_INVALIDARG** | The *pIID* parameter either is not a valid BSTR or does not translate into a valid GUID. |
| **E_NOINTERFACE** | The interface requested is not exposed or the object does not implement the **IObjectSafety** interface. |

## Remarks

The application must use
[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring) to allocate memory for the *pIID* parameter and use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory when the variable is no longer needed.

The Dispatch Mapper will use the object's **IObjectSafety** interface to make sure the object is safe for scripting on the requested interface. If the object does not implement **IObjectSafety**, or if the object is not safe on this particular interface, the call will fail.

## See also

[ITDispatchMapper](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itdispatchmapper)