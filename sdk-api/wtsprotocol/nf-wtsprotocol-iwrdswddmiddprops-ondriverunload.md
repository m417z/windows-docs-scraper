# IWRdsWddmIddProps::OnDriverUnload

## Description

Termsrv uses this method to tell the protocol stack that PnP unloaded the
WDDM ID driver.

## Parameters

### `SessionId` [in]

ID of a session driver is unloaded from.

## Return value

Returns S_OK or error code

## See also

[IWRdsWddmIddProps](https://learn.microsoft.com/windows/win32/api/wtsprotocol/nn-wtsprotocol-iwrdswddmiddprops)