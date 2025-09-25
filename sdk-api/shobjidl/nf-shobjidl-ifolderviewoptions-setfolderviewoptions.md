# IFolderViewOptions::SetFolderViewOptions

## Description

Sets specified options for the view.

## Parameters

### `fvoMask` [in]

Type: **[FOLDERVIEWOPTIONS](https://learn.microsoft.com/windows/desktop/api/shobjidl/ne-shobjidl-folderviewoptions)**

A bitmask made up of one or more of the [FOLDERVIEWOPTIONS](https://learn.microsoft.com/windows/desktop/api/shobjidl/ne-shobjidl-folderviewoptions) flags to indicate which options' are being changed. Values in *fvoFlags* not included in this mask are ignored.

### `fvoFlags` [in]

Type: **[FOLDERVIEWOPTIONS](https://learn.microsoft.com/windows/desktop/api/shobjidl/ne-shobjidl-folderviewoptions)**

A bitmask that contains the new values for the options specified in *fvoMask*. To enable an option, the bitmask should include the [FOLDERVIEWOPTIONS](https://learn.microsoft.com/windows/desktop/api/shobjidl/ne-shobjidl-folderviewoptions) flag for that option. To disable an option, the bit used for that **FOLDERVIEWOPTIONS** flag should be 0.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.