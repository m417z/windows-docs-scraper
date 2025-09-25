## Description

Specifies whether or not protected resources can be accessed by subsequent commands in the command list. By default, no protected resources are enabled. After calling **SetProtectedResourceSession** with a valid session, protected resources of the same type can refer to that session. After calling **SetProtectedResourceSession** with **NULL**, no protected resources can be accessed.

## Parameters

### `pProtectedResourceSession` [in, optional]

Type: **[ID3D12ProtectedResourceSession](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12protectedresourcesession)\***

An optional pointer to an **ID3D12ProtectedResourceSession**. You can obtain an **ID3D12ProtectedResourceSession** by calling [ID3D12Device4::CreateProtectedResourceSession](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device4-createprotectedresourcesession).

## Return value

If set, indicates that protected resources can be accessed with the given session. Access to protected resources can only happen after **SetProtectedResourceSession** is called with a valid session. The command list state is cleared when calling this method. If you pass **NULL**, then no protected resources can be accessed.

## See also

[ID3D12GraphicsCommandList3](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12graphicscommandlist3)