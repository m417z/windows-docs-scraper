# IDXGIFactory::EnumAdapters

## Description

Enumerates the adapters (video cards).

## Parameters

### `Adapter`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index of the adapter to enumerate.

### `ppAdapter` [out]

Type: **[IDXGIAdapter](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiadapter)****

The address of a pointer to an [IDXGIAdapter](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiadapter) interface at the position specified by the *Adapter* parameter. This parameter must not be **NULL**.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if successful; otherwise, returns [DXGI_ERROR_NOT_FOUND](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) if the index is greater than or equal to the number of adapters in the local system, or [DXGI_ERROR_INVALID_CALL](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) if *ppAdapter* parameter is **NULL**.

## Remarks

When you create a factory, the factory enumerates the set of adapters that are available in the system. Therefore, if you change the adapters in a system, you must destroy
and recreate the [IDXGIFactory](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgifactory) object. The number of adapters in a system changes when you add or remove a display card, or dock or undock a laptop.

When the **EnumAdapters** method succeeds and fills the *ppAdapter* parameter with the address of the pointer to the adapter interface, **EnumAdapters** increments the adapter interface's reference count. When you finish using the
adapter interface, call the [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method to decrement the reference count before you destroy the pointer.

**EnumAdapters** first returns the adapter with the output on which the desktop primary is displayed. This adapter corresponds with an index of zero. **EnumAdapters** next returns other adapters with outputs. **EnumAdapters** finally returns adapters without outputs.

#### Examples

Enumerating Adapters

The following code example demonstrates how to enumerate adapters using the **EnumAdapters** method.

```

UINT i = 0;
IDXGIAdapter * pAdapter;
std::vector <IDXGIAdapter*> vAdapters;
while(pFactory->EnumAdapters(i, &pAdapter) != DXGI_ERROR_NOT_FOUND)
{
	vAdapters.push_back(pAdapter);
	++i;
}

```

## See also

[DXGI Interfaces](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-interfaces)

[IDXGIFactory](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgifactory)