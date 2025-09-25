# IDirect3DDevice9::CreateQuery

## Description

Creates a status query.

## Parameters

### `Type` [in]

Type: **[D3DQUERYTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dquerytype)**

Identifies the query type. For more information, see [D3DQUERYTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dquerytype).

### `ppQuery` [out, retval]

Type: **[IDirect3DQuery9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dquery9)****

Returns a pointer to the query interface that manages the query object. See [IDirect3DQuery9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dquery9).

This parameter can be set to **NULL** to see if a query is supported. If the query is not supported, the method returns D3DERR_NOTAVAILABLE.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be D3DERR_NOTAVAILABLE or E_OUTOFMEMORY.

## Remarks

This method is provided for both synchronous and asynchronous queries. It takes the place of GetInfo, which is no longer supported in Direct3D 9.

Synchronous and asynchronous queries are created with **IDirect3DDevice9::CreateQuery** with [D3DQUERYTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dquerytype). When a query has been created and the API calls have been made that are being queried, use [IDirect3DQuery9::Issue](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3dquery9-issue) to issue a query and [IDirect3DQuery9::GetData](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3dquery9-getdata) to get the results of the query.

## See also

[Asynchronous Notification (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/asynchronous-notification)

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)