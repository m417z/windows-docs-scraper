# IDirect3D9::GetAdapterMonitor

## Description

Returns the handle of the monitor associated with the Direct3D object.

## Parameters

### `Adapter` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Ordinal number that denotes the display adapter. D3DADAPTER_DEFAULT is always the primary display adapter.

## Return value

Type: **[HMONITOR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle of the monitor associated with the Direct3D object.

## Remarks

As shown in the following code fragment, which illustrates how to obtain a handle to the monitor associated with a given device, use [GetDirect3D](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-getdirect3d) to return the Direct3D enumerator from the device and use [GetCreationParameters](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-getcreationparameters) to retrieve the value for Adapter.

```

    if( FAILED( pDevice->GetCreationParameters(  &Parameters ) ) )
        return D3DERR_INVALIDCALL;

    if( FAILED( pDevice->GetDirect3D(&pD3D) ) )
        return D3DERR_INVALIDCALL;

    hMonitor = pD3D->GetAdapterMonitor(Parameters.AdapterOrdinal);

    pD3D->Release();

```

## See also

[GetCreationParameters](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-getcreationparameters)

[GetDirect3D](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-getdirect3d)

[IDirect3D9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3d9)