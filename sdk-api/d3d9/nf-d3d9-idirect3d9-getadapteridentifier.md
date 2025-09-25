# IDirect3D9::GetAdapterIdentifier

## Description

Describes the physical display adapters present in the system when the [IDirect3D9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3d9) interface was instantiated.

## Parameters

### `Adapter` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Ordinal number that denotes the display adapter. D3DADAPTER_DEFAULT is always the primary display adapter. The minimum value for this parameter is 0, and the maximum value for this parameter is one less than the value returned by [GetAdapterCount](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3d9-getadaptercount).

### `Flags` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flags sets the **WHQLLevel** member of [D3DADAPTER_IDENTIFIER9](https://learn.microsoft.com/windows/desktop/direct3d9/d3dadapter-identifier9). Flags can be set to either 0 or D3DENUM_WHQL_LEVEL. If D3DENUM_WHQL_LEVEL is specified, this call can connect to the Internet to download new Microsoft Windows Hardware Quality Labs (WHQL) certificates.

Differences between Direct3D 9 and Direct3D 9Ex:

D3DENUM_WHQL_LEVEL is deprecated for Direct3D9Ex running on Windows Vista, Windows Server 2008, Windows 7, and Windows Server 2008 R2 (or more current operating system). Any of these operating systems return 1 in the **WHQLLevel** member of [D3DADAPTER_IDENTIFIER9](https://learn.microsoft.com/windows/desktop/direct3d9/d3dadapter-identifier9) without checking the status of the driver.

### `pIdentifier` [out]

Type: **[D3DADAPTER_IDENTIFIER9](https://learn.microsoft.com/windows/desktop/direct3d9/d3dadapter-identifier9)***

Pointer to a [D3DADAPTER_IDENTIFIER9](https://learn.microsoft.com/windows/desktop/direct3d9/d3dadapter-identifier9) structure to be filled with information describing this adapter. If *Adapter* is greater than or equal to the number of adapters in the system, this structure will be zeroed.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. D3DERR_INVALIDCALL is returned if Adapter is out of range, if Flags contains unrecognized parameters, or if pIdentifier is **NULL** or points to unwritable memory.

## See also

[GetAdapterCount](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3d9-getadaptercount)

[IDirect3D9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3d9)