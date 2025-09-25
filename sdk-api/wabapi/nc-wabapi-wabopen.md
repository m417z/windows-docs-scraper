# WABOpen callback function

## Description

Do not use. Provides access to the address book through a number of object interfaces. The root interface is [IAddrBook](https://learn.microsoft.com/windows/desktop/api/wabiab/nn-wabiab-iaddrbook), which is a subset of the MAPI implementation of [IAddrBook](https://learn.microsoft.com/windows/desktop/api/wabiab/nn-wabiab-iaddrbook).

## Parameters

### `lppAdrBook`

Type: **LPADRBOOK***

Address of a pointer to the [IAddrBook](https://learn.microsoft.com/windows/desktop/api/wabiab/nn-wabiab-iaddrbook) interface returned by the function.

### `lppWABObject`

Type: **LPWABOBJECT***

Address of a pointer to the [IWABObject](https://learn.microsoft.com/windows/desktop/api/wabapi/nn-wabapi-iwabobject) interface returned by the function.

### `lpWP`

### `Reserved2`

Type: **DWORD**

Reserved. Must be set to 0.

#### - lpWABParam

Type: **LPWAB_PARAM**

Pointer to a [WAB_PARAM](https://learn.microsoft.com/windows/desktop/api/wabapi/ns-wabapi-wab_param) structure. Supported by Internet Explorer 4.0 or later.

## Return value

Type: **HRESULT**

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[WABOpenEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/wabapi/nc-wabapi-wabopenex)