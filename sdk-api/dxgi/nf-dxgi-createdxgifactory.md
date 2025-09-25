# CreateDXGIFactory function

## Description

Creates a DXGI 1.0 factory that you can use to generate other DXGI objects.

## Parameters

### `riid`

Type: **REFIID**

The globally unique identifier (GUID) of the [IDXGIFactory](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgifactory) object referenced by the *ppFactory* parameter.

### `ppFactory` [out]

Type: **void****

Address of a pointer to an [IDXGIFactory](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgifactory) object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns **S_OK** if successful; otherwise, returns one of the following [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

## Remarks

Use a DXGI factory to generate objects that [enumerate adapters](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgifactory-enumadapters), [create swap chains](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgifactory-createswapchain), and [associate a window](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgifactory-makewindowassociation) with the alt+enter key sequence for toggling to and from the fullscreen display mode.

If the **CreateDXGIFactory** function succeeds, the reference count on the [IDXGIFactory](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgifactory) interface is incremented. To avoid a memory leak, when you finish using the interface, call the [IDXGIFactory::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method to release the interface.

**Note** Do not mix the use of DXGI 1.0 ([IDXGIFactory](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgifactory)) and DXGI 1.1 ([IDXGIFactory1](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgifactory1)) in an application. Use **IDXGIFactory** or **IDXGIFactory1**, but not both in an application.

**Note** **CreateDXGIFactory** fails if your app's [DllMain](https://learn.microsoft.com/windows/desktop/Dlls/dllmain) function calls it. For more info about how DXGI responds from **DllMain**, see [DXGI Responses from DLLMain](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-programming-guide-dxgi).

**Note** Starting with Windows 8, all DXGI factories (regardless if they were created with **CreateDXGIFactory** or [CreateDXGIFactory1](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-createdxgifactory1)) enumerate adapters identically. The enumeration order of adapters, which you retrieve with [IDXGIFactory::EnumAdapters](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgifactory-enumadapters) or [IDXGIFactory1::EnumAdapters1](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgifactory1-enumadapters1), is as follows:

* Adapter with the output on which the desktop primary is displayed. This adapter corresponds with an index of zero.
* Adapters with outputs.
* Adapters without outputs.

The **CreateDXGIFactory** function does not exist for Windows Store apps. Instead, Windows Store apps use the [CreateDXGIFactory1](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-createdxgifactory1) function.

#### Examples

Creating a DXGI 1.0 Factory

The following code example demonstrates how to create a DXGI 1.0 factory. This example uses the __uuidof() intrinsic to obtain the REFIID, or GUID, of the [IDXGIFactory](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgifactory) interface.

```

IDXGIFactory * pFactory;
HRESULT hr = CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)(&pFactory) );

```

## See also

[DXGI Functions](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-functions)