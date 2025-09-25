# IDeskBand2::SetCompositionState

## Description

Sets the composition state.

**Important** You should use [thumbnail toolbars](https://learn.microsoft.com/windows/desktop/shell/taskbar-extensions) in new development in place of desk bands, which are not supported as of Windows 7.

## Parameters

### `fCompositionEnabled` [in]

Type: **BOOL**

**TRUE** to enable the composition state; otherwise, **FALSE**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.