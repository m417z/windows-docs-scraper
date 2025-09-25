# IShellImageData::GetProperties

## Description

Gets an [IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage) through which the properties of the image can be accessed.

## Parameters

### `dwMode` [in]

Type: **DWORD**

Not used, set to 0.

### `ppPropSet` [out]

Type: **[IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage)****

The address of a pointer to the [IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage) interface.

## Return value

Type: **HRESULT**

Returns **S_OK** if successful or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **E_FAIL** | The image has not been decoded or the decoding process failed. |
| **E_POINTER** | The *ppPropSet* pointer is not valid. |