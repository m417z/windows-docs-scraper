## Description

Unregisters a callback that was registered with [RegisterDestructionCallback](https://learn.microsoft.com/windows/win32/api/d3dcommon/nf-d3dcommon-id3ddestructionotifier-registerdestructioncallback).

## Parameters

### `callbackID`

Type: **[UINT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The **UINT** that was created by the *pCallbackID* argument to **[ID3DDestructionNotifier::RegisterDestructionCallback](https://learn.microsoft.com/windows/win32/api/d3dcommon/nf-d3dcommon-id3ddestructionotifier-registerdestructioncallback)**.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this function succeeds, it returns **S_OK**.

## See also

[ID3DDestructionNotifier](https://learn.microsoft.com/windows/win32/api/d3dcommon/nn-d3dcommon-id3ddestructionotifier)

[ID3DDestructionNotifier::RegisterDestructionCallback](https://learn.microsoft.com/windows/win32/api/d3dcommon/nf-d3dcommon-id3ddestructionotifier-registerdestructioncallback)