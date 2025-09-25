# IExpDispSupport::OnTranslateAccelerator

## Description

Deprecated. Instructs the control site to process the keystroke described in *pMsg* and modified by the flags in *grfModifiers*.

## Parameters

### `pMsg`

Type: **[MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg)***

A pointer to an [MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg) structure that describes the keystroke to be processed.

### `grfModifiers`

Type: **DWORD**

Flags describing the state of the CTRL, ALT, and SHIFT keys. The value of the flags can be any valid [KEYMODIFIERS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683763(v=vs.85)) enumeration value or values.

## Return value

Type: **HRESULT**

Returns **S_OK** if the container processed the message, **S_FALSE** if the container did not process the message, or **E_NOTIMPL** if the container does not implement accelerator support.