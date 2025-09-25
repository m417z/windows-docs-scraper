# IMathInputControl::SetOwnerWindow

## Description

Modifies the window that owns this control.

## Parameters

### `OwnerWindow` [in]

A handle to the owner window.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The math input control always appears on top of the window that owns it.

## See also

[IMathInputControl](https://learn.microsoft.com/windows/desktop/api/micaut/nn-micaut-imathinputcontrol)