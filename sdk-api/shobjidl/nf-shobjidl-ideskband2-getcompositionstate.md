# IDeskBand2::GetCompositionState

## Description

Gets the composition state.

**Important** You should use [thumbnail toolbars](https://learn.microsoft.com/windows/desktop/shell/taskbar-extensions) in new development in place of desk bands, which are not supported as of Windows 7.

## Parameters

### `pfCompositionEnabled` [out]

Type: **BOOL***

When this method returns, contains a **BOOL** that indicates state.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.