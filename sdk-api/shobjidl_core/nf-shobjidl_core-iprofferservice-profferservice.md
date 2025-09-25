# IProfferService::ProfferService

## Description

Makes a service available to other objects on the same host.

## Parameters

### `guidService` [in]

Type: **REFGUID**

A value of type **GUID** that specifies the service being offered.

### `psp` [in]

Type: **[IServiceProvider](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/cc678965(v=vs.85))***

A pointer to an [IServiceProvider](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/cc678965(v=vs.85)) interface.

### `pdwCookie` [out]

Type: **DWORD***

A pointer to a **DWORD** that receives an implementation-defined value used for identification purposes. The calling application must keep track of this value for possible use in [IProfferService::RevokeService](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iprofferservice-revokeservice).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IProfferService](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iprofferservice)

[IProfferService::RevokeService](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iprofferservice-revokeservice)

[IServiceProvider](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/cc678965(v=vs.85))