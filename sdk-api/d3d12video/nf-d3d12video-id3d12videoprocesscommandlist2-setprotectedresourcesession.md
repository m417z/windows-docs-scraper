## Description

Specifies whether or not protected resources can be accessed by subsequent commands in the video process command list. By default, no protected resources are enabled. After calling **SetProtectedResourceSession** with a valid session, protected resources of the same type can refer to that session. After calling **SetProtectedResourceSession** with **NULL**, no protected resources can be accessed.

## Parameters

### `pProtectedResourceSession`

An optional pointer to an [ID3D12ProtectedResourceSession](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12protectedresourcesession). You can obtain an **ID3D12ProtectedResourceSession** by calling [ID3D12Device4::CreateProtectedResourceSession](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device4-createprotectedresourcesession).

## Remarks

## See also