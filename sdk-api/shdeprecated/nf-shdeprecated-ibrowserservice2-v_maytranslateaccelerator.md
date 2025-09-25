# IBrowserService2::v_MayTranslateAccelerator

## Description

Deprecated. Called by a derived class to instruct the base class to proceed with the translation of keyboard mnemonics.

## Parameters

### `pmsg` [in]

Type: **[MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg)***

A pointer to a [MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg) that contains the keystroke message.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.