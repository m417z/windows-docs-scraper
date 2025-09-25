# ID3D12ProtectedSession::GetSessionStatus

## Description

Gets the status of the protected session.

## Return value

Type: **[D3D12_PROTECTED_SESSION_STATUS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_protected_session_status)**

The status of the protected session. If the returned value is [D3D12_PROTECTED_SESSION_STATUS_INVALID](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_protected_session_status), then you need to wait for a uniqueness value bump to reuse the resource if the session is an [ID3D12ProtectedResourceSession](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12protectedresourcesession).

## See also

[ID3D12ProtectedSession](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12protectedsession)