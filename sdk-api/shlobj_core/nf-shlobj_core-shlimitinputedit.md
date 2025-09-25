# SHLimitInputEdit function

## Description

[This function is available through Windows XP Service Pack 2 (SP2) and Windows Server 2003. It might be altered or unavailable in subsequent versions of Windows.]

Sets limits on valid characters for an edit control.

## Parameters

### `hwndEdit` [in, optional]

Type: **HWND**

The handle of the edit control.

### `psf` [in]

Type: **[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)***

An [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) interface pointer. This object must also implement [IItemNameLimits](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iitemnamelimits), which supplies a list of invalid characters and a maximum name length.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.