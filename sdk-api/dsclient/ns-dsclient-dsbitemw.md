# DSBITEMW structure

## Description

The **DSBITEM** structure contains data about an item in the Active Directory container browser dialog box. This structure is passed with the **DSBM_QUERYINSERT** notification to the [BFFCallBack](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nc-shlobj_core-bffcallback) callback function. The container browser dialog box is created with the [DsBrowseForContainer](https://learn.microsoft.com/windows/desktop/api/dsclient/nf-dsclient-dsbrowseforcontainera) function.

## Members

### `cbStruct`

Contains the size, in bytes, of the structure.

### `pszADsPath`

Pointer to a null-terminated Unicode string that contains the ADsPath of the item.

### `pszClass`

Pointer to a null-terminated Unicode string that contains the object class name of the item.

### `dwMask`

Contains a set of flags that indicate which members of the structure contain valid data. This can be zero or a combination of one or more of the following values.

#### DSBF_DISPLAYNAME

The **szDisplayName** member contains valid data.

#### DSBF_ICONLOCATION

The **szIconLocation** and **iIconResID** members contain valid data.

#### DSBF_STATE

The **dwState** and **dwStateMask** members contain valid data.

### `dwState`

Contains a set of flags that indicate the state of the item. This can be zero or a combination of one or more of the following values.

#### DSBS_CHECKED

If this flag is set, the item is selected. Otherwise, the item is not selected. This flag is not currently supported.

#### DSBS_HIDDEN

If this flag is set, the item is hidden. Otherwise, the item is visible.

#### DSBS_ROOT

If this flag is set, the item is a root item. Otherwise, the item is not a root item.

### `dwStateMask`

Contains a set of flags that indicate which flags in the **dwState** member contain valid data. This can be zero or a combination of one or more of the following values. For example, if **dwStateMask** has the **DSBS_HIDDEN** flag set and **dwState** does not have the **DSBS_HIDDEN** flag set, then the item is visible. If **dwStateMask** does not have the **DSBS_HIDDEN** flag set, then the **DSBS_HIDDEN** flag in **dwState** must be ignored.

#### DSBS_CHECKED

The **DSBS_CHECKED** flag in the **dwState** member contains valid data.

#### DSBS_HIDDEN

The **DSBS_HIDDEN** flag in the **dwState** member contains valid data.

#### DSBS_ROOT

The **DSBS_ROOT** flag in the **dwState** member contains valid data.

### `szDisplayName`

Pointer to a null-terminated string that contains the display name of the item. The display name of an item can be changed by copying the new display name into this member, setting the **DSBF_DISPLAYNAME** flag in the **dwMask** member, and returning a nonzero value from [BFFCallBack](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nc-shlobj_core-bffcallback).

### `szIconLocation`

Pointer to a null-terminated string that contains the name of an .exe, .dll, or .ico file that contains the icon to display for the item. This can be any file type that can be passed to the [ExtractIcon](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-extracticona) function. The index for this icon is specified in **iIconResID**. To modify the icon displayed for the item, copy the icon source file name into this member, set **iIconResID** to the zero-based index of the icon, set the **DSBF_ICONLOCATION** flag in the **dwMask** member, and return a nonzero value from [BFFCallBack](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nc-shlobj_core-bffcallback).

### `iIconResID`

Contains the zero-based index of the icon to display for the item.

**Note** This is not the resource identifier of the icon.

##### - dwMask.DSBF_DISPLAYNAME

The **szDisplayName** member contains valid data.

##### - dwMask.DSBF_ICONLOCATION

The **szIconLocation** and **iIconResID** members contain valid data.

##### - dwMask.DSBF_STATE

The **dwState** and **dwStateMask** members contain valid data.

##### - dwState.DSBS_CHECKED

If this flag is set, the item is selected. Otherwise, the item is not selected. This flag is not currently supported.

##### - dwState.DSBS_HIDDEN

If this flag is set, the item is hidden. Otherwise, the item is visible.

##### - dwState.DSBS_ROOT

If this flag is set, the item is a root item. Otherwise, the item is not a root item.

##### - dwStateMask.DSBS_CHECKED

The **DSBS_CHECKED** flag in the **dwState** member contains valid data.

##### - dwStateMask.DSBS_HIDDEN

The **DSBS_HIDDEN** flag in the **dwState** member contains valid data.

##### - dwStateMask.DSBS_ROOT

The **DSBS_ROOT** flag in the **dwState** member contains valid data.

## See also

[BFFCallBack](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nc-shlobj_core-bffcallback)

[DsBrowseForContainer](https://learn.microsoft.com/windows/desktop/api/dsclient/nf-dsclient-dsbrowseforcontainera)

[ExtractIcon](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-extracticona)

## Remarks

> [!NOTE]
> The dsclient.h header defines DSBITEM as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).