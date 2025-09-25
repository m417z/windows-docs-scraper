## Description

Configures the SDK version to use.

## Parameters

### `SDKVersion`

Type: **[UINT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The SDK version to set.

### `SDKPath`

Type: \_In\_z\_ **[LPCSTR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A NULL-terminated string that provides the relative path to `d3d12core.dll` at the specified *SDKVersion*. The path is relative to the process exe of the caller. If `d3d12core.dll` isn't found, or isn't of the specified *SDKVersion*, then Direct3D 12 device creation fails.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, then it returns **S_OK**. Otherwise, it returns one of the [Direct3D 12 return codes](https://learn.microsoft.com/windows/win32/direct3d12/d3d12-graphics-reference-returnvalues).

## Remarks

This method can be used only in Windows Developer Mode.

To set the SDK version using this API, you must call it before you create the Direct3D 12 device. Calling this API *after* creating the Direct3D 12 device will cause the Direct3D 12 runtime to remove the device.

If the `d3d12core.dll` installed with the OS is newer than the SDK version specified, then the OS version is used instead.

You can retrieve the version of a particular `D3D12Core.dll` from the exported symbol [**D3D12SDKVersion**](https://learn.microsoft.com/windows/win32/direct3d12/nf-d3d12-d3d12sdkversion), which is a variable of type **UINT**, just like the variables exported from applications to enable use of the Agility SDK.

## See also