# IDeskBand2::CanRenderComposited

## Description

Indicates the deskband's ability to be displayed as translucent.

**Important** You should use [thumbnail toolbars](https://learn.microsoft.com/windows/desktop/shell/taskbar-extensions) in new development in place of desk bands, which are not supported as of Windows 7.

## Parameters

### `pfCanRenderComposited` [out]

Type: **BOOL***

When this method returns, contains a **BOOL** indicating ability.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.