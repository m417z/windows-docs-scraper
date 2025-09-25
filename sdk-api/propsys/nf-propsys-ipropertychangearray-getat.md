# IPropertyChangeArray::GetAt

## Description

Gets the change operation at a specified array index.

## Parameters

### `iIndex` [in]

Type: **UINT**

The index of the change to retrieve.

### `riid` [in]

Type: **REFIID**

A reference to the desired IID.

### `ppv` [out]

Type: **void****

The address of a pointer to the interface specified by *riid*, usually [IPropertyChange](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertychange).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.