# IDirect3DQuery9::Issue

## Description

Issue a query.

## Parameters

### `dwIssueFlags` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Query flags specify the type of state change for the query. See [D3DISSUE_BEGIN](https://learn.microsoft.com/windows/desktop/direct3d9/d3dissue-begin) and [D3DISSUE_END](https://learn.microsoft.com/windows/desktop/direct3d9/d3dissue-end).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be D3DERR_INVALIDCALL.

## Remarks

A signaled query means the query has completed, the data is available, and [IDirect3DQuery9::GetData](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3dquery9-getdata) will return S_OK.

## See also

[IDirect3DQuery9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dquery9)