# IAccPropServices::ComposeHmenuIdentityString

## Description

Callers use **ComposeHmenuIdentityString**
to retrieve an identity string for an **HMENU**-based accessible element.

## Parameters

### `hmenu` [in]

Type: **[HMENU](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Identifies the **HMENU**-based accessible element.

### `idChild` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the child ID of the accessible element.

### `ppIDString` [out]

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)****

Pointer to a buffer that receives the identity string. The callee allocates this buffer using [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc). When finished, the caller must free the buffer by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

### `pdwIDStringLen` [out]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Pointer to a buffer that receives the length of the identity string.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK.

Returns E_INVALIDARG if *hmenu* or *idChild* is not valid.

May return other error codes under exceptional error conditions such as low memory.