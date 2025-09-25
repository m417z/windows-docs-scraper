# FOLDERFLAGS enumeration

## Description

A set of flags that specify folder view options. The flags are independent of each other and can be used in any combination.

## Constants

### `FWF_NONE:0`

0x00000000. **Windows 7 and later**. No special view options.

### `FWF_AUTOARRANGE:0x1`

0x00000001. Automatically arrange the elements in the view. This implies [LVS_AUTOARRANGE](https://learn.microsoft.com/windows/desktop/Controls/list-view-window-styles) if the list-view control is used to implement the view.

### `FWF_ABBREVIATEDNAMES:0x2`

0x00000002. Not supported.

### `FWF_SNAPTOGRID:0x4`

0x00000004. Not supported.

### `FWF_OWNERDATA:0x8`

0x00000008. Not supported.

### `FWF_BESTFITWINDOW:0x10`

0x00000010. Not supported.

### `FWF_DESKTOP:0x20`

0x00000020. Make the folder behave like the desktop. This value applies only to the desktop and is not used for typical Shell folders. This flag implies **FWF_NOCLIENTEDGE** and **FWF_NOSCROLL**.

### `FWF_SINGLESEL:0x40`

0x00000040. Do not allow more than a single item to be selected. This is used in the common dialog boxes.

### `FWF_NOSUBFOLDERS:0x80`

0x00000080. Do not show subfolders.

### `FWF_TRANSPARENT:0x100`

0x00000100. Draw transparently. This is used only for the desktop.

### `FWF_NOCLIENTEDGE:0x200`

0x00000200. Not supported.

### `FWF_NOSCROLL:0x400`

0x00000400. Do not add scroll bars. This is used only for the desktop.

### `FWF_ALIGNLEFT:0x800`

0x00000800. The view should be left-aligned. This implies [LVS_ALIGNLEFT](https://learn.microsoft.com/windows/desktop/Controls/list-view-window-styles) if the list-view control is used to implement the view.

### `FWF_NOICONS:0x1000`

0x00001000. The view should not display icons.

### `FWF_SHOWSELALWAYS:0x2000`

0x00002000. This flag is deprecated as of Windows XP and has no effect. Always show the selection.

### `FWF_NOVISIBLE:0x4000`

0x00004000. Not supported.

### `FWF_SINGLECLICKACTIVATE:0x8000`

0x00008000. Not supported.

### `FWF_NOWEBVIEW:0x10000`

0x00010000. The view should not be shown as a web view.

### `FWF_HIDEFILENAMES:0x20000`

0x00020000. The view should not display file names.

### `FWF_CHECKSELECT:0x40000`

0x00040000. Turns on the check mode for the view.

### `FWF_NOENUMREFRESH:0x80000`

0x00080000. **Windows Vista and later**. Do not re-enumerate the view (or drop the current contents of the view) when the view is refreshed.

### `FWF_NOGROUPING:0x100000`

0x00100000. **Windows Vista and later**. Do not allow grouping in the view

### `FWF_FULLROWSELECT:0x200000`

0x00200000. **Windows Vista and later**. When an item is selected, the item and all its sub-items are highlighted.

### `FWF_NOFILTERS:0x400000`

0x00400000. **Windows Vista and later**. Do not display filters in the view.

### `FWF_NOCOLUMNHEADER:0x800000`

0x00800000. **Windows Vista and later**. Do not display a column header in the view in any view mode.

### `FWF_NOHEADERINALLVIEWS:0x1000000`

0x01000000. **Windows Vista and later**. Only show the column header in details view mode.

### `FWF_EXTENDEDTILES:0x2000000`

0x02000000. **Windows Vista and later**. When the view is in "tile view mode" the layout of a single item should be extended to the width of the view.

### `FWF_TRICHECKSELECT:0x4000000`

0x04000000. **Windows Vista and later**. Not supported.

### `FWF_AUTOCHECKSELECT:0x8000000`

0x08000000. **Windows Vista and later**. Items can be selected using checkboxes.

### `FWF_NOBROWSERVIEWSTATE:0x10000000`

0x10000000. **Windows Vista and later**. The view should not save view state in the browser.

### `FWF_SUBSETGROUPS:0x20000000`

0x20000000. **Windows Vista and later**. The view should list the number of items displayed in each group. To be used with [IFolderView2::SetGroupSubsetCount](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifolderview2-setgroupsubsetcount).

### `FWF_USESEARCHFOLDER:0x40000000`

0x40000000. **Windows Vista and later**. Use the search folder for stacking and searching.

### `FWF_ALLOWRTLREADING:0x80000000`

(int)0x80000000. **Windows Vista and later**. Ensure right-to-left reading layout in a right-to-left system. Without this flag, the view displays strings from left-to-right both on systems set to left-to-right and right-to-left reading layout, which ensures that file names display correctly.