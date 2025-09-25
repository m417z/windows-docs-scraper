# IOpenControlPanel::GetPath

## Description

Gets the path of a specified Control Panel item.

## Parameters

### `pszName` [in]

Type: **LPCWSTR**

A pointer to the item's canonical name or its **GUID**. This value can be **NULL**. See Remarks for further details. For a complete list of Control Panel item canonical names, see [Canonical Names of Control Panel Items](https://learn.microsoft.com/windows/desktop/shell/controlpanel-canonical-names).

### `pszPath` [out]

Type: **LPWSTR**

When this method returns, contains the path of the specified Control Panel item as a Unicode string.

### `cchPath` [in]

Type: **UINT**

The size of the buffer pointed to by *pszPath*, in WCHARs.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If *pszName* points to the item's canonical name or **GUID**, then the path returned is in one of these two forms, depending on the most recent Control Panel view (Classic View or Category View):

```cpp
::{CLSID_ControlPanel}\::{item guid}
::{CLSID_ControlPanelCategory}\categoryId\::{item guid}

```

If *pszName* is **NULL** then one of these two values is returned:

```cpp
::{CLSID_ControlPanel}
::{CLSID_ControlPanelCategory}

```

## See also

[Developing for the Control Panel](https://learn.microsoft.com/previous-versions/bb757044(v=msdn.10))

[IOpenControlPanel](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iopencontrolpanel)