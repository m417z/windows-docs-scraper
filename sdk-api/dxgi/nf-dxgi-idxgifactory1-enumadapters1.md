# IDXGIFactory1::EnumAdapters1

## Description

Enumerates both adapters (video cards) with or without outputs.

## Parameters

### `Adapter`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index of the adapter to enumerate.

### `ppAdapter` [out]

Type: **[IDXGIAdapter1](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiadapter1)****

The address of a pointer to an [IDXGIAdapter1](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiadapter1) interface at the position specified by the *Adapter* parameter.
This parameter must not be **NULL**.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if successful; otherwise, returns [DXGI_ERROR_NOT_FOUND](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) if the index is greater than or equal to the number of adapters in the local
system, or [DXGI_ERROR_INVALID_CALL](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) if *ppAdapter* parameter is **NULL**.

## Remarks

This method is not supported by DXGI 1.0, which shipped in Windows Vista and Windows Server 2008. DXGI 1.1 support is required, which is available on
Windows 7, Windows Server 2008 R2, and as an update to Windows Vista with Service Pack 2 (SP2) ([KB 971644](https://support.microsoft.com/topic/application-compatibility-update-for-windows-vista-windows-server-2008-windows-7-and-windows-server-2008-r2-february-2010-3eb7848b-9a76-85fe-98d0-729e3827ea60)) and Windows Server 2008 ([KB 971512](https://support.microsoft.com/kb/971512/)).

When you create a factory, the factory enumerates the set of adapters that are available in the system. Therefore, if you change the adapters in a system, you must destroy
and recreate the [IDXGIFactory1](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgifactory1) object. The number of adapters in a system changes when you add or remove a display card, or dock or undock a laptop.

When the **EnumAdapters1** method succeeds and fills the *ppAdapter* parameter with the address of the pointer to the adapter interface, **EnumAdapters1** increments the adapter interface's reference count. When you finish using the
adapter interface, call the [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method to decrement the reference count before you destroy the pointer.

**EnumAdapters1** first returns the adapter with the output on which the desktop primary is displayed. This adapter corresponds with an index of zero. **EnumAdapters1** next returns other adapters with outputs. **EnumAdapters1** finally returns adapters without outputs.

#### Examples

Enumerating Adapters

The following code example demonstrates how to enumerate adapters using the **EnumAdapters1** method.

```

UINT i = 0;
IDXGIAdapter1 * pAdapter;
std::vector <IDXGIAdapter1*> vAdapters;
while(pFactory->EnumAdapters1(i, &pAdapter) != DXGI_ERROR_NOT_FOUND)
{
	vAdapters.push_back(pAdapter);
	++i;
}

```

## See also

[DXGI Interfaces](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-interfaces)

[IDXGIFactory1](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgifactory1)