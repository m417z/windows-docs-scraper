# IWRdsWddmIddProps::OnDriverLoad

## Description

Termsrv uses this method to return a handle of the loaded WDDM ID driver to
the protocol stack. From this point the stack owns the handle and needs to call
CloseHandle() after communication with the driver is no longer needed.

## Parameters

### `SessionId` [in]

ID of the session that the driver is loaded for.

### `DriverHandle` [in]

Opened handle of the WDDM ID driver.

## Return value

S_OK or error code

## See also

[IWRdsWddmIddProps](https://learn.microsoft.com/windows/win32/api/wtsprotocol/nn-wtsprotocol-iwrdswddmiddprops)