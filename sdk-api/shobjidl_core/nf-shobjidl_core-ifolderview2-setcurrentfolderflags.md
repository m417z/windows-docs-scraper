# IFolderView2::SetCurrentFolderFlags

## Description

Sets and applies specified folder flags.

## Parameters

### `dwMask` [in]

Type: **DWORD**

The value of type **DWORD** that specifies the bitmask indicating which items in the structure are desired or valid.

### `dwFlags` [in]

Type: **DWORD**

The value of type **DWORD** that contains one or more [FOLDERFLAGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-folderflags).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**For Windows 7 or later:** This method must be used in combination with the *FVO_CUSTOMPOSITION* flag from the [FOLDERVIEWOPTIONS](https://learn.microsoft.com/windows/desktop/api/shobjidl/ne-shobjidl-folderviewoptions) enumeration.