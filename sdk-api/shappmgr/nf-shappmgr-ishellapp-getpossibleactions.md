# IShellApp::GetPossibleActions

## Description

Gets a bitmask of management actions allowed for an application.

## Parameters

### `pdwActions` [out]

Type: **DWORD***

A pointer to a variable of type **DWORD** that returns the bitmask of supported actions. The bit flags are described in [APPACTIONFLAGS](https://learn.microsoft.com/windows/desktop/api/shappmgr/ne-shappmgr-appactionflags).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Of the set of [APPACTIONFLAGS](https://learn.microsoft.com/windows/desktop/api/shappmgr/ne-shappmgr-appactionflags) bitmasks, Add/Remove Programs only recognizes APPACTION_INSTALL and APPACTION_ADDLATER.

## See also

[IAppPublisher](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-iapppublisher)

[IPublishedApp](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-ipublishedapp)

[IShellApp](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-ishellapp)