# IDXGIFactory::CreateSoftwareAdapter

## Description

Create an adapter interface that represents a software adapter.

## Parameters

### `Module`

Type: **[HMODULE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the software adapter's dll. HMODULE can be obtained with [GetModuleHandle](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getmodulehandlea) or [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya).

### `ppAdapter` [out]

Type: **[IDXGIAdapter](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiadapter)****

Address of a pointer to an adapter (see [IDXGIAdapter](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiadapter)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

A [return code](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) indicating success or failure.

## Remarks

A software adapter is a DLL that implements the entirety of a device driver interface, plus emulation, if necessary, of kernel-mode graphics components for Windows. Details on implementing a software adapter can be found in the Windows Vista Driver Development Kit. This is a very complex development task, and is not recommended for general readers.

Calling this method will increment the module's reference count by one. The reference count can be decremented by calling [FreeLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-freelibrary).

The typical calling scenario is to call [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya), pass the handle to **CreateSoftwareAdapter**, then immediately call [FreeLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-freelibrary) on the DLL and forget the DLL's [HMODULE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types). Since the software adapter calls **FreeLibrary** when it is destroyed, the lifetime of the DLL will now be owned by the adapter, and the application is free of any further consideration of its lifetime.

## See also

[IDXGIFactory](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgifactory)