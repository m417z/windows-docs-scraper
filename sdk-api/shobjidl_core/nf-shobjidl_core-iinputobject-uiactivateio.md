# IInputObject::UIActivateIO

## Description

UI-activates or deactivates the object.

## Parameters

### `fActivate` [in]

Type: **BOOL**

Indicates if the object is being activated or deactivated. If this value is nonzero, the object is being activated. If this value is zero, the object is being deactivated.

### `pMsg` [in]

Type: **[MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg)***

A pointer to an [MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg) structure that contains the message that caused the activation change. This value may be **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.