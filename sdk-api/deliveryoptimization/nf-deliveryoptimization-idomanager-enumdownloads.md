## Description

Retrieves an interface pointer to an enumerator object that is used to enumerate existing downloads.

## Parameters

### `category`

Optional. The property name to be used as a category to enumerate. Passing `nullptr` will retrieve all existing downloads. The following properties are supported as a category.

- **DODownloadProperty_Id**
- **DODownloadProperty_Uri**
- **DODownloadProperty_ContentId**
- **DODownloadProperty_DisplayName**
- **DODownloadProperty_LocalPath**

### `ppEnum`

The address of an interface pointer to **IEnumUnknown**, which is used to enumerate existing downloads. The contents of the enumerator depend on the value of *category*. The downloads included in the enumeration interface are the ones that were previously created by the same caller to this function.

## Return value

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

## Remarks

## See also