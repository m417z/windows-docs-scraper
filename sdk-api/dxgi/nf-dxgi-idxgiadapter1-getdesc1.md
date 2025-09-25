# IDXGIAdapter1::GetDesc1

## Description

Gets a DXGI 1.1 description of an adapter (or video card).

## Parameters

### `pDesc` [out]

Type: **[DXGI_ADAPTER_DESC1](https://learn.microsoft.com/windows/desktop/api/dxgi/ns-dxgi-dxgi_adapter_desc1)***

A pointer to a [DXGI_ADAPTER_DESC1](https://learn.microsoft.com/windows/desktop/api/dxgi/ns-dxgi-dxgi_adapter_desc1) structure that describes the adapter.
This parameter must not be **NULL**. On [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 9 graphics hardware, **GetDesc1** returns zeros for **VendorId**, **DeviceId**, **SubSysId**, and **Revision** members of **DXGI_ADAPTER_DESC1** and “Software Adapter” for the description string in the **Description** member.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if successful; otherwise, returns E_INVALIDARG if the *pDesc* parameter is **NULL**.

## Remarks

This method is not supported by DXGI 1.0, which shipped in Windows Vista and Windows Server 2008. DXGI 1.1 support is required, which is available on
Windows 7, Windows Server 2008 R2, and as an update to Windows Vista with Service Pack 2 (SP2) ([KB 971644](https://support.microsoft.com/topic/application-compatibility-update-for-windows-vista-windows-server-2008-windows-7-and-windows-server-2008-r2-february-2010-3eb7848b-9a76-85fe-98d0-729e3827ea60)) and Windows Server 2008 ([KB 971512](https://support.microsoft.com/kb/971512/)).

Use the **GetDesc1** method to get a DXGI 1.1 description of an adapter. To get a DXGI 1.0 description, use the [IDXGIAdapter](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiadapter) method.

## See also

[DXGI Interfaces](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-interfaces)

[IDXGIAdapter1](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiadapter1)

[IDXGIAdapter::GetDesc](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiadapter-getdesc)