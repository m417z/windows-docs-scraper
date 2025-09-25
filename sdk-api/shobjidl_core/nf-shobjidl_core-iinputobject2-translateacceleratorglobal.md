# IInputObject2::TranslateAcceleratorGlobal

## Description

Handles global accelerators so that input objects can respond to the keyboard even when they are not active in the UI.

## Parameters

### `pMsg` [in]

Type: **[MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg)***

A pointer to an [MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg) structure that contains a keyboard message.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.