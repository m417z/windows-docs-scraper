# IPropertyChangeArray::InsertAt

## Description

Inserts a change operation into an array at the specified position.

## Parameters

### `iIndex` [in]

Type: **UINT**

The index at which the change is inserted.

### `ppropChange` [in]

Type: **[IPropertyChange](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertychange)***

A pointer to the interface that contains the change.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.