# NSTCFOLDERCAPABILITIES enumeration

## Description

Specifies the state of a tree item. These values are used by methods of the [INameSpaceTreeControlFolderCapabilities](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-inamespacetreecontrolfoldercapabilities) interface.

## Constants

### `NSTCFC_NONE:0`

The property does not exist. Filtering is not supported.

### `NSTCFC_PINNEDITEMFILTERING:0x1`

Property exists. Supports filtering based on the value specified in [System.IsPinnedToNameSpaceTree](https://learn.microsoft.com/windows/desktop/properties/props-system-ispinnedtonamespacetree).

### `NSTCFC_DELAY_REGISTER_NOTIFY:0x2`

Delays registration for change notifications until the tree is expanded in the navigation pane.

## Remarks

The **NSTCFOLDERCAPABILITIES** type is defined in Shobjidl.h beginning in Windows 7.

## See also

[INameSpaceTreeControlFolderCapabilities::GetFolderCapabilities](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-inamespacetreecontrolfoldercapabilities-getfoldercapabilities)