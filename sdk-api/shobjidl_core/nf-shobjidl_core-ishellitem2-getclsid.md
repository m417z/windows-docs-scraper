# IShellItem2::GetCLSID

## Description

Gets the class identifier (CLSID) value of specified property key.

## Parameters

### `key` [in]

Type: **REFPROPERTYKEY**

A reference to a [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure.

### `pclsid` [out]

Type: **CLSID***

A pointer to a CLSID value.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.