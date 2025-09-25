# IAccPropServices::DecomposeHmenuIdentityString

## Description

Use this method to determine the **HMENU**, object ID, and child ID for the accessible element identified by the identity string.

## Parameters

### `pIDString` [in]

Type: **const [BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Pointer to a buffer containing identity string of an **HMENU**-based accessible element.

### `dwIDStringLen` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the length of the identity string specified by *pIDString*.

### `phmenu` [out]

Type: **[HMENU](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Pointer to a buffer that receives the **HMENU** of the accessible element.

### `pidChild` [out]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Pointer to a buffer that receives the child ID of the accessible element.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK.

Returns E_INVALIDARG if *phmenu* or *pidChild* are not valid, or if the given identity string is not a **HMENU**-based identity string.

May return other error codes under exceptional error conditions such as low memory.

## Remarks

This method succeeds only if the provided identity string is an **HMENU**-based identity string. This method is useful in an [IAccPropServer](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccpropserver) callback server that was registered with ANNO_CONTAINER scope because it allows the server to determine, from the given identity string, the child element (*idChild*) for which the client is calling the server.