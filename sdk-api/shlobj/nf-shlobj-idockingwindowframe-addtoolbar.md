# IDockingWindowFrame::AddToolbar

## Description

Adds the specified [IDockingWindow](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idockingwindow) object to the frame.

## Parameters

### `punkSrc` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to the [IDockingWindow](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idockingwindow) object to be added.

### `pwszItem` [in]

Type: **PCWSTR**

A pointer to a null-terminated, Unicode, application-defined string that is used to identify the docking window object.

### `dwAddFlags`

Type: **DWORD**

Flags that apply to the docking window object that is being added. One or more of the following values.

#### 0

The docking window is a regular, visible docking window.

#### DWFAF_HIDDEN (0x0001)

The docking window is added but is not shown. To show it at a later time, call its [IDockingWindow::ShowDW](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idockingwindow-showdw) method.

#### DWFAF_GROUP1 (0x0002)

Reserved. Do not use.

#### DWFAF_GROUP2 (0x0004)

Reserved. Do not use.

#### DWFAF_AUTOHIDE (0x0010)

Reserved. Do not use.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDockingWindowFrame](https://learn.microsoft.com/windows/desktop/api/shlobj/nn-shlobj-idockingwindowframe)

[IDockingWindowSite](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-idockingwindowsite)