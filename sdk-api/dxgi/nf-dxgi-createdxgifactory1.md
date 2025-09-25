# CreateDXGIFactory1 function

## Description

Creates a DXGI 1.1 factory that you can use to generate other DXGI objects.

## Parameters

### `riid`

Type: **REFIID**

The globally unique identifier (GUID) of the [IDXGIFactory1](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgifactory1) object referenced by
the *ppFactory* parameter.

### `ppFactory` [out]

Type: **void****

Address of a pointer to an [IDXGIFactory1](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgifactory1) object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if successful; an error code otherwise. For a list of error codes, see [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

## Remarks

Use a DXGI 1.1 factory to generate objects that [enumerate adapters](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgifactory-enumadapters),
[create swap chains](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgifactory-createswapchain), and [associate a window](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgifactory-makewindowassociation) with
the alt+enter key sequence for toggling to and from the full-screen display mode.

If the **CreateDXGIFactory1** function succeeds, the reference count on the [IDXGIFactory1](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgifactory1) interface is incremented. To avoid a memory leak, when you finish using the interface, call the [IDXGIFactory1::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method to release the interface.

This entry point is not supported by DXGI 1.0, which shipped in Windows Vista and Windows Server 2008. DXGI 1.1 support is required, which is available on
Windows 7, Windows Server 2008 R2, and as an update to Windows Vista with Service Pack 2 (SP2) ([KB 971644](https://support.microsoft.com/topic/application-compatibility-update-for-windows-vista-windows-server-2008-windows-7-and-windows-server-2008-r2-february-2010-3eb7848b-9a76-85fe-98d0-729e3827ea60)) and Windows Server 2008 ([KB 971512](https://support.microsoft.com/kb/971512/)).

**Note** Do not mix the use of DXGI 1.0 ([IDXGIFactory](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgifactory)) and DXGI 1.1 ([IDXGIFactory1](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgifactory1)) in an application. Use **IDXGIFactory** or **IDXGIFactory1**, but not both in an application.

**Note** **CreateDXGIFactory1** fails if your app's [DllMain](https://learn.microsoft.com/windows/desktop/Dlls/dllmain) function calls it. For more info about how DXGI responds from **DllMain**, see [DXGI Responses from DLLMain](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-programming-guide-dxgi).

**Note** Starting with Windows 8, all DXGI factories (regardless if they were created with [CreateDXGIFactory](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-createdxgifactory) or **CreateDXGIFactory1**) enumerate adapters identically. The enumeration order of adapters, which you retrieve with [IDXGIFactory::EnumAdapters](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgifactory-enumadapters) or [IDXGIFactory1::EnumAdapters1](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgifactory1-enumadapters1), is as follows:

* Adapter with the output on which the desktop primary is displayed. This adapter corresponds with an index of zero.
* Adapters with outputs.
* Adapters without outputs.

#### Examples

Creating a DXGI 1.1 Factory

The following code example demonstrates how to create a DXGI 1.1 factory. This example uses the __uuidof() intrinsic to
obtain the REFIID, or GUID, of the [IDXGIFactory1](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgifactory1) interface.

```

IDXGIFactory1 * pFactory;
HRESULT hr = CreateDXGIFactory1(__uuidof(IDXGIFactory1), (void**)(&pFactory) );

```

## See also

[DXGI Functions](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-functions)