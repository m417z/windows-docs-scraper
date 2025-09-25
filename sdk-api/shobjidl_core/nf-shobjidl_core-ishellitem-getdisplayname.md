# IShellItem::GetDisplayName

## Description

Gets the display name of the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) object.

## Parameters

### `sigdnName` [in]

Type: **[SIGDN](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-sigdn)**

One of the [SIGDN](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-sigdn) values that indicates how the name should look.

### `ppszName` [out]

Type: **LPWSTR***

A value that, when this function returns successfully, receives the address of a pointer to the retrieved display name.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

It is the responsibility of the caller to free the string pointed to by *ppszName* when it is no longer needed. Call [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) on **ppszName* to free the memory.

## See also

[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)

[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)