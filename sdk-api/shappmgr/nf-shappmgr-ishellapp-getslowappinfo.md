# IShellApp::GetSlowAppInfo

## Description

Returns information to the application that originates from a slow source. This method is not applicable to published applications.

## Parameters

### `psaid` [out]

Type: **PSLOWAPPINFO**

A pointer to a [SLOWAPPINFO](https://learn.microsoft.com/windows/desktop/api/shappmgr/ns-shappmgr-slowappinfo) structure in which to return application information.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Implementations of [IPublishedApp](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-ipublishedapp) should return E_NOTIMPL. This method is used internally by Add/Remove Programs for installed applications.

## See also

[IAppPublisher](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-iapppublisher)

[IPublishedApp](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-ipublishedapp)

[IShellApp](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-ishellapp)