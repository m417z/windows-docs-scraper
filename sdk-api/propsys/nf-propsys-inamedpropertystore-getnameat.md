# INamedPropertyStore::GetNameAt

## Description

Gets the name of a property at a specified index in the property store.

## Parameters

### `iProp` [in]

Type: **DWORD**

The index of the property in the store.

### `pbstrName` [out]

Type: **[BSTR](https://learn.microsoft.com/previous-versions/windows/desktop/automat/bstr)***

When this method returns, contains a pointer to the property's name. It is the calling application's responsibility to free this resource when it is no longer needed.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.