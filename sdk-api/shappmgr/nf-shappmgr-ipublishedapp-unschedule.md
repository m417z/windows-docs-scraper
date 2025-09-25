# IPublishedApp::Unschedule

## Description

Cancels the installation of an application published by an application publisher.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is called in each of the following circumstances.

1. The user selected the **Do Not Add Program** option in the **Add Later** dialog box in **Add/Remove Programs** in Control Panel.
2. The user has selected an installation time later than either the expiration time or the assigned time as specified in the published application information. In these circumstances, implementations are expected to cancel any scheduled installation for the application.

## See also

[IAppPublisher](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-iapppublisher)

[IPublishedApp](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-ipublishedapp)

[IPublishedApp::GetPublishedAppInfo](https://learn.microsoft.com/windows/desktop/api/shappmgr/nf-shappmgr-ipublishedapp-getpublishedappinfo)

[IShellApp](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-ishellapp)