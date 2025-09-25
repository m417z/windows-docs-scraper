# INewShortcutHookW::SetReferent

## Description

Sets the referent of the shortcut object.

## Parameters

### `pcszReferent`

TBD

### `hwnd`

TBD

### `hWnd` [in, optional]

Type: **HWND**

A handle to the window that will be used as the parent if the object needs to display a message box or dialog box. This value can be **NULL**.

#### - pszReferent [in]

Type: **PCTSTR**

A pointer to a string that contains the referent.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For Internet shortcut objects, this method is the same as [IUniformResourceLocator::SetURL](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/dd565676(v=vs.85)).