# IPublishedApp::Install

## Description

Installs an application published by an application publisher. This method is invoked when the user selects **Add** or **Add Later** in **Add/Remove Programs** in Control Panel.

## Parameters

### `pstInstall` [in]

Type: **LPSYSTEMTIME**

A pointer to a [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that specifies the time the user elected to schedule installation through the **Add Later** button in **Add/Remove Programs**. This option is only available if the application supports scheduled installation (compare [GetPossibleActions](https://learn.microsoft.com/windows/desktop/api/shappmgr/nf-shappmgr-ishellapp-getpossibleactions)). If this parameter is **NULL**, the application should be installed immediately.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[GetPossibleActions](https://learn.microsoft.com/windows/desktop/api/shappmgr/nf-shappmgr-ishellapp-getpossibleactions)

[IAppPublisher](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-iapppublisher)

[IPublishedApp](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-ipublishedapp)