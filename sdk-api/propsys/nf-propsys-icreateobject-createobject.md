# ICreateObject::CreateObject

## Description

Creates a local object of a specified class and returns a pointer to a specified interface on the object.

## Parameters

### `clsid` [in]

Type: **REFCLSID**

A reference to a CLSID.

### `pUnkOuter` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface that aggregates the object created by this function, or **NULL** if no aggregation is desired.

### `riid` [in]

Type: **REFIID**

A reference to the IID of the interface the created object should return.

### `ppv` [out]

Type: **void****

When this method returns, contains the address of the pointer to the interface requested in *riid*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method can be used with [GetPropertyStoreWithCreateObject](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellitem2-getpropertystorewithcreateobject).