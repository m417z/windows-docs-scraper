# IBrowserService::RegisterWindow

## Description

Deprecated. Registers the browser in the list of browser windows.

## Parameters

### `fForceRegister`

Type: **BOOL**

A value of type **BOOL** that indicates whether to reregister the browser window if it was previously registered. If set to **TRUE** and the window was previously registered, this method will unregister and reregister the browser window.

#### TRUE

Force the window to be unregistered then reregistered.

#### FALSE

If the window is already registered, do nothing.

### `swc`

Type: **int**

One of the [ShellWindowTypeConstants](https://learn.microsoft.com/windows/desktop/api/exdisp/ne-exdisp-shellwindowtypeconstants) values to indicate the nature of the window. Note that these values are defined in Expdisp.h.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.