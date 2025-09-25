# OleCreateDefaultHandler function

## Description

Creates a new instance of the default embedding handler. This instance is initialized so it creates a local server when the embedded object enters the running state.

## Parameters

### `clsid` [in]

CLSID identifying the OLE server to be loaded when the embedded object enters the running state.

### `pUnkOuter` [in]

 Pointer to the controlling [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface if the handler is to be aggregated; **NULL** if it is not to be aggregated.

### `riid` [in]

Reference to the identifier of the interface, usually IID_IOleObject, through which the caller will communicate with the handler.

### `lplpObj` [out]

Address of pointer variable that receives the interface pointer requested in riid. Upon successful return, **ppvObj* contains the requested interface pointer on the newly created handler.

## Return value

This function returns NOERROR on success and supports the standard return value E_OUTOFMEMORY.

## Remarks

**OleCreateDefaultHandler** creates a new instance of the default embedding handler, initialized so it creates a local server identified by the *clsid* parameter when the embedded object enters the running state. If you are writing a handler and want to use the services of the default handler, call **OleCreateDefaultHandler**. OLE also calls it internally when the CLSID specified in an object creation call is not registered.

If the given class does not have a special handler, a call to **OleCreateDefaultHandler** produces the same results as a call to the [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance) function with the class context parameter assigned the value CLSCTX_INPROC_HANDLER.

## See also

[CLSCTX](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ne-wtypesbase-clsctx)

[CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance)