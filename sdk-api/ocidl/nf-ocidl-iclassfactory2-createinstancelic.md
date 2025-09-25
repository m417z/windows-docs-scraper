# IClassFactory2::CreateInstanceLic

## Description

Creates an instance of the licensed object for the specified license key. This method is the only possible means to create an object on an otherwise unlicensed machine.

## Parameters

### `pUnkOuter` [in]

A pointer to the controlling [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface on the outer unknown if this object is being created as part of an aggregate. If the object is not part of an aggregate, this parameter must be **NULL**.

### `pUnkReserved` [in]

This parameter is unused and must be **NULL**.

### `riid` [in]

A reference to the identifier of the interface to be used to communicate with the newly created object.

### `bstrKey` [in]

Run-time license key previously obtained from [IClassFactory2::RequestLicKey](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iclassfactory2-requestlickey) that is required to create an object.

### `ppvObj` [out]

Address of pointer variable that receives the interface pointer requested in *riid*. Upon successful return, **ppvObj* contains the requested interface pointer. If an error occurs, the implementation must set **ppvObj* to **NULL**.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The license was successfully created. |
| **E_NOTIMPL** | This method is not implemented because objects can only be created on fully licensed machines through [IClassFactory::CreateInstance](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iclassfactory-createinstance). |
| **E_POINTER** | A pointer passed in *bstrKey* or *ppvObj* is not valid. For example, it may be **NULL**. |
| **E_NOINTERFACE** | The object can be created (and the license key is valid) except the object does not support the interface specified by *riid*. |
| **CLASS_E_NOAGGREGATION** | The *pUnkOuter* parameter is non-**NULL**, but this object class does not support aggregation. |
| **CLASS_E_NOTLICENSED** | The key provided in *bstrKey* is not a valid license key. |

## Remarks

### Notes to Implementers

If the class factory does not provide a license key (that is, [IClassFactory2::RequestLicKey](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iclassfactory2-requestlickey) returns E_NOTIMPL and the **fRuntimeKeyAvail** member in [LICINFO](https://learn.microsoft.com/windows/desktop/api/ocidl/ns-ocidl-licinfo) is set to **FALSE** in [IClassFactory2::GetLicInfo](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iclassfactory2-getlicinfo)), then this method can also return E_NOTIMPL. In such cases, the class factory is implementing [IClassFactory2](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iclassfactory2) simply to specify whether the machine is licensed at all through the **fLicVerified** member of **LICINFO**.

## See also

[IClassFactory2](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iclassfactory2)

[LICINFO](https://learn.microsoft.com/windows/desktop/api/ocidl/ns-ocidl-licinfo)