# IPropertyDescriptionSearchInfo::GetMaxSize

## Description

Gets the maximum size value from the property schema's [searchInfo](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-searchinfo) element.

## Parameters

### `pcbMaxSize` [out]

Type: **UINT***

Pointer to a value that, when this method returns successfully, receives the value of the maxSize attribute of the [searchInfo](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-searchinfo) element. The default is:

* **Windows Vista**: 128 bytes
* **Windows 7 and later**: 512 bytes

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.