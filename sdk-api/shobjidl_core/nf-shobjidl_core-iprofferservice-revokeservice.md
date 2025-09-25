# IProfferService::RevokeService

## Description

Makes a service unavailable that had previously been available to other objects through [IProfferService::ProfferService](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iprofferservice-profferservice).

## Parameters

### `dwCookie` [in]

Type: **DWORD**

A value of type **DWORD** that specifies an implementation-defined value used for identification purposes. The calling application receives this value from [IProfferService::ProfferService](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iprofferservice-profferservice).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IProfferService](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iprofferservice)

[IProfferService::ProfferService](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iprofferservice-profferservice)