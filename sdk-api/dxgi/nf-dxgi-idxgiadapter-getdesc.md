# IDXGIAdapter::GetDesc

## Description

Gets a DXGI 1.0 description of an adapter (or video card).

## Parameters

### `pDesc` [out]

Type: **[DXGI_ADAPTER_DESC](https://learn.microsoft.com/windows/desktop/api/dxgi/ns-dxgi-dxgi_adapter_desc)***

A pointer to a [DXGI_ADAPTER_DESC](https://learn.microsoft.com/windows/desktop/api/dxgi/ns-dxgi-dxgi_adapter_desc) structure that describes the adapter. This parameter must not be **NULL**. On [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 9 graphics hardware, **GetDesc** returns zeros for **VendorId**, **DeviceId**, **SubSysId**, and **Revision** members of **DXGI_ADAPTER_DESC** and “Software Adapter” for the description string in the **Description** member.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if successful; otherwise returns E_INVALIDARG if the *pDesc* parameter is **NULL**.

## Remarks

Graphics apps can use the DXGI API to retrieve an accurate set of graphics memory
values on systems that have Windows Display Driver Model (WDDM) drivers. The following are the critical steps involved.

* Graphics driver model determination —Because DXGI is only available on systems with WDDM drivers, the app must first confirm the driver model by using the following API.

  ```

  HasWDDMDriver()
  {
      LPDIRECT3DCREATE9EX pD3D9Create9Ex = NULL;
      HMODULE             hD3D9          = NULL;

      hD3D9 = LoadLibrary( L"d3d9.dll" );

      if ( NULL == hD3D9 ) {
          return false;
      }

      //
      /*  Try to create IDirect3D9Ex interface (also known as a DX9L interface). This interface can only be created if the driver is a WDDM driver.
  	 */
      //
      pD3D9Create9Ex = (LPDIRECT3DCREATE9EX) GetProcAddress( hD3D9, "Direct3DCreate9Ex" );

      return pD3D9Create9Ex != NULL;
  }

  ```
* Retrieval of graphics memory values.—After the app determines the driver model to be WDDM, the app can use the Direct3D 10 or later API and DXGI to get the amount of graphics memory.
  After you create a Direct3D device, use this code to obtain
  a [DXGI_ADAPTER_DESC](https://learn.microsoft.com/windows/desktop/api/dxgi/ns-dxgi-dxgi_adapter_desc) structure that contains the amount of available graphics memory.

  ```

  IDXGIDevice * pDXGIDevice;
  hr = g_pd3dDevice->QueryInterface(__uuidof(IDXGIDevice), (void **)&pDXGIDevice);
  IDXGIAdapter * pDXGIAdapter;
  pDXGIDevice->GetAdapter(&pDXGIAdapter);
  DXGI_ADAPTER_DESC adapterDesc;
  pDXGIAdapter->GetDesc(&adapterDesc);

  ```

## See also

[DXGI Interfaces](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-interfaces)

[IDXGIAdapter](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiadapter)