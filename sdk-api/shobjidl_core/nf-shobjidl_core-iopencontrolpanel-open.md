# IOpenControlPanel::Open

## Description

Opens the specified Control Panel item, optionally to a specific page.

## Parameters

### `pszName` [in]

Type: **LPCWSTR**

A pointer to the item's canonical name as a Unicode string. This parameter is optional and can be **NULL**. If the calling application passes **NULL**, then the Control Panel itself opens. For a complete list of Control Panel item canonical names, see [Canonical Names of Control Panel Items](https://learn.microsoft.com/windows/desktop/shell/controlpanel-canonical-names).

### `pszPage` [in]

Type: **LPCWSTR**

A pointer to the name of the page within the item to display. This string is appended to the end of the path for Shell folder Control Panel items or appended as a command-line parameter for Control Panel (.cpl) file items. This parameter can be **NULL**, in which case the first page is shown.

### `punkSite` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to the site for navigating in-frame for Shell folder Control Panel items. This parameter can be **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Developing for the Control Panel](https://learn.microsoft.com/previous-versions/bb757044(v=msdn.10))

[IOpenControlPanel](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iopencontrolpanel)