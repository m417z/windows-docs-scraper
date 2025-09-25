# IPublishedApp2::Install2

## Description

Installs an application published by an application publisher, while preventing multiple windows from being active on the same thread.

## Parameters

### `pstInstall` [in]

Type: **LPSYSTEMTIME**

A pointer to a [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure.

### `hwndParent` [in]

Type: **HWND**

A handle to the parent window.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.