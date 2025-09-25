# IPropertyChangeArray::AppendOrReplace

## Description

Replaces the first occurrence of a change that affects the same property key as the provided change. If the property key is not already in the array, this method appends the change to the end of the array.

## Parameters

### `ppropChange` [in]

Type: **[IPropertyChange](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertychange)***

A pointer to the interface that contains the change

## Return value

Type: **HRESULT**

Returns **S_OK** if successful, or an error value otherwise.