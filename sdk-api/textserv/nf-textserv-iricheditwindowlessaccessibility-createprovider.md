# IRicheditWindowlessAccessibility::CreateProvider

## Description

Obtains a Microsoft UI Automation provider object for the parent of a windowless rich edit control.

## Parameters

### `pSite`

Type: **IRawElementProviderWindowlessSite***

The ActiveX control site that hosts the windowless rich edit control.

### `ppProvider`

Type: **IRawElementProviderSimple****

The UI Automation provider for the windowless rich edit control's parent.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IRicheditWindowlessAccessibility](https://learn.microsoft.com/windows/desktop/api/textserv/nn-textserv-iricheditwindowlessaccessibility)