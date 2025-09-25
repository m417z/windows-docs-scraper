# SHGetNameFromIDList function

## Description

Retrieves the display name of an item identified by its IDList.

## Parameters

### `pidl` [in]

Type: **PCIDLIST_ABSOLUTE**

A PIDL that identifies the item.

### `sigdnName` [in]

Type: **[SIGDN](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-sigdn)**

A value from the [SIGDN](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-sigdn) enumeration that specifies the type of display name to retrieve.

### `ppszName` [out]

Type: **PWSTR***

A value that, when this function returns successfully, receives the address of a pointer to the retrieved display name.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

It is the responsibility of the caller to free the string pointed to by *ppszName* when it is no longer needed. Call [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) on **ppszName* to free the memory.