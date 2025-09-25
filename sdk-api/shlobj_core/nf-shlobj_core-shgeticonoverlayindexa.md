# SHGetIconOverlayIndexA function

## Description

Returns the index of the overlay icon in the system image list.

## Parameters

### `pszIconPath` [in, optional]

Type: **LPCTSTR**

A pointer to a null-terminated string of maximum length **MAX_PATH** that contains the fully qualified path of the file that contains the icon.

### `iIconIndex`

Type: **int**

The icon's index in the file pointed to by *pszIconPath*. To request a standard overlay icon, set *pszIconPath* to **NULL**, and *iIconIndex* to one of the following:

#### IDO_SHGIOI_SHARE (0x0FFFFFFF)

The overlay icon that indicates a shared folder.

#### IDO_SHGIOI_LINK (0x0FFFFFFE)

The overlay icon that indicates a linked folder or file.

#### IDO_SHGIOI_SLOWFILE (0x0FFFFFFD)

The overlay icon that indicates a slow file.

#### IDO_SHGIOI_DEFAULT (0x0FFFFFFC)

**Windows 7 and later**. The overlay icon that indicates that the item is the default in a set. One example is the default printer.

## Return value

Type: **int**

Returns the index of the overlay icon in the system image list if successful, or -1 otherwise.

## Remarks

Icon overlays are part of the system image list. They have two identifiers. The first is a one-based overlay index that identifies the overlay relative to other overlays in the image list. The other is an image index that identifies the actual image. These two indexes are equivalent to the values that you assign to the *iOverlay* and *iImage* parameters, respectively, when you add an icon overlay to a private image list with [ImageList_SetOverlayImage](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-imagelist_setoverlayimage). **SHGetIconOverlayIndex** returns the overlay index. To convert an overlay index to its equivalent image index, call [INDEXTOOVERLAYMASK](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-indextooverlaymask).

**Note** After the image has been loaded into the system image list during initialization, it cannot be changed. The file name and index specified by *pszIconPath* and *iIconIndex* are used only to identify the icon overlay. **SHGetIconOverlayIndex** cannot be used to modify the system image list.

> [!NOTE]
> The shlobj_core.h header defines SHGetIconOverlayIndex as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[IShellIconOverlay](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-ishelliconoverlay)

[IShellIconOverlayIdentifier](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelliconoverlayidentifier)