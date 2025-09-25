## Description

Registers a user-defined callback to be invoked on destruction of the object from which this [ID3DDestructionNotifier](https://learn.microsoft.com/windows/win32/api/d3dcommon/nn-d3dcommon-id3ddestructionotifier) was created.

## Parameters

### `callbackFn`

Type: **PFN_DESTRUCTION_CALLBACK**

A user-defined callback to be invoked when the object is destroyed.

### `pData`

Type: **void\***

The data to pass to *callbackFn* when invoked

### `pCallbackID`

Type: **[UINT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to a **UINT** used to identify the callback, and to pass to  to unregister the callback.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this function succeeds, it returns **S_OK**.

## Remarks

An example of this interface being used to log the destruction of an **ID3D12Resource**.

```cppcx
#include <d3dcommon.h> // for ID3DDestructionNotifier

ComPtr<ID3D12Resource> resource = ...;

ComPtr<ID3DDestructionNotifier> notifier;
if (SUCCEEDED(resource.As(&notifier)))
{
    UINT callbackId;
    ThrowIfFailed(notifier->RegisterDestructionCallback(LogResourceReleased, nullptr, &callbackId));
}

void LogResourceReleased(void* context)
{
    OutputDebugString("Resource released!\n");
}
```

## See also

[ID3DDestructionNotifier](https://learn.microsoft.com/windows/win32/api/d3dcommon/nn-d3dcommon-id3ddestructionotifier)

[ID3DDestructionNotifier::UnregisterDestructionCallback](https://learn.microsoft.com/windows/win32/api/d3dcommon/nf-d3dcommon-id3ddestructionotifier-unregisterdestructioncallback)