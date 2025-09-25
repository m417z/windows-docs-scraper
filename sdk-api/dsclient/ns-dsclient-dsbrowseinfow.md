# DSBROWSEINFOW structure

## Description

The **DSBROWSEINFO** structure is used with the
[DsBrowseForContainer](https://learn.microsoft.com/windows/desktop/api/dsclient/nf-dsclient-dsbrowseforcontainera) function to supply and return data about the Active Directory container browser dialog box.

## Members

### `cbStruct`

Contains the size, in bytes, of the **DSBROWSEINFO** structure. This is used by the [DsBrowseForContainer](https://learn.microsoft.com/windows/desktop/api/dsclient/nf-dsclient-dsbrowseforcontainera) function for versioning purposes.

### `hwndOwner`

Handle of the window used as the parent of the container browser dialog box.

### `pszCaption`

Pointer to a null-terminated string that contains the caption of the dialog box. If this member is **NULL**, a default caption is used.

### `pszTitle`

Pointer to a null-terminated string that contains additional text to be displayed in the dialog box above the tree control. If this member is **NULL**, no additional text is displayed.

### `pszRoot`

Pointer to a null-terminated Unicode string that contains the ADsPath of the container placed at the root of the dialog box. The user cannot navigate above this level using the dialog box.

### `pszPath`

Pointer to a null-terminated Unicode string that receives the ADsPath of the container selected in the dialog. This string will always be null-terminated even if **cchPath** is not large enough to hold the entire path. If **dwFlags** contains the **DSBI_EXPANDONOPEN** flag, this member contains the ADsPath of the container that should be initially selected in the dialog box.

### `cchPath`

Contains the size, in **WCHAR** characters, of the **pszPath** buffer.

### `dwFlags`

Contains a set of flags that define the behavior of the dialog box. This can be zero or a combination of one or more of the following values.

#### DSBI_NOBUTTONS (1 (0x1))

The **+** and **-** buttons are not displayed in the dialog box.

#### DSBI_NOLINES (2 (0x2))

The lines that connect the objects in the dialog box are not displayed.

#### DSBI_NOLINESATROOT (4 (0x4))

The lines and buttons above the root objects are not displayed.

#### DSBI_CHECKBOXES (256 (0x100))

Causes a check box to be placed next to each item in the tree. The user can use the mouse to select and clear this check box. This currently has limited usage because there is no way to set or get the check state of an item.

#### DSBI_NOROOT (65536 (0x10000))

The root object, specified by **pszRoot**, is not displayed and the immediate child objects of the root are displayed at the root of the tree. This flag has no effect if **pszRoot** is **NULL** or if this member contains **DSBI_ENTIREDIRECTORY**.

#### DSBI_INCLUDEHIDDEN (131072 (0x20000))

Include hidden objects in the dialog box.

#### DSBI_EXPANDONOPEN (262144 (0x40000))

When the dialog box opens, the container specified in **pszPath** will be visible and selected.

#### DSBI_ENTIREDIRECTORY (589824 (0x90000))

Includes all the trusted domains to the server specified in **pszRoot** or, by default, the domain that the user is logged in to.

#### DSBI_RETURN_FORMAT (1048576 (0x100000))

Indicates that the **dwReturnFormat** member is valid. If this flag is not set, the path format defaults to X.500.

#### DSBI_HASCREDENTIALS (2097152 (0x200000))

**pUserName** and **pPassword** are used for the access credentials. Otherwise, if this member does not contain **DSBI_SIMPLEAUTHENTICATE**, the dialog uses the security context of the calling thread.

#### DSBI_IGNORETREATASLEAF (4194304 (0x400000))

When determining if the object is displayed in the dialog box, the **treatAsLeaf** display specifier is ignored.

#### DSBI_SIMPLEAUTHENTICATE (8388608 (0x800000))

Indicates that secure authentication is not required when calling [ADsOpenObject](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsopenobject).

#### DSBI_RETURNOBJECTCLASS (16777216 (0x1000000))

Indicates that the **pszObjectClass** and **cchObjectClass** are valid and should be filled.

#### DSBI_DONTSIGNSEAL (33554432 (0x2000000))

Indicates that signing and sealing will not be used when communicating with the directory service.

### `pfnCallback`

Pointer to an application-defined [BFFCallBack](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nc-shlobj_core-bffcallback) callback function that receives notifications from the container browser dialog box. Set this member to **NULL** if it is not used.

### `lParam`

Contains an application-defined 32-bit value passed as the *lpData* parameter in all calls to **pfnCallback**. This member is ignored if **pfnCallback** is **NULL**.

### `dwReturnFormat`

Contains one of the [ADS_FORMAT_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_format_enum) values that specifies the format that the ADSI path returned in **pszPath** will accept.

### `pUserName`

Pointer to a Unicode string that contains the user name used for the credentials. This member is ignored if **dwFlags** does not have the **DSBI_HASCREDENTIALS** flag set. If this member is **NULL**, the currently logged on user name is used.

### `pPassword`

Pointer to a Unicode string that contains the password used for the credentials. This member is ignored if **dwFlags** does not have the **DSBI_HASCREDENTIALS** flag set. If this member is **NULL**, the password of the currently logged on user is used.

### `pszObjectClass`

Pointer to a Unicode string buffer that receives the class string of the selected. This member is ignored if **dwFlags** does not have the **DSBI_RETURNOBJECTCLASS** flag set.

### `cchObjectClass`

Contains the size, in **WCHAR** characters, of the **pszObjectClass** buffer.

##### - dwFlags.DSBI_CHECKBOXES (256 (0x100))

Causes a check box to be placed next to each item in the tree. The user can use the mouse to select and clear this check box. This currently has limited usage because there is no way to set or get the check state of an item.

##### - dwFlags.DSBI_DONTSIGNSEAL (33554432 (0x2000000))

Indicates that signing and sealing will not be used when communicating with the directory service.

##### - dwFlags.DSBI_ENTIREDIRECTORY (589824 (0x90000))

Includes all the trusted domains to the server specified in **pszRoot** or, by default, the domain that the user is logged in to.

##### - dwFlags.DSBI_EXPANDONOPEN (262144 (0x40000))

When the dialog box opens, the container specified in **pszPath** will be visible and selected.

##### - dwFlags.DSBI_HASCREDENTIALS (2097152 (0x200000))

**pUserName** and **pPassword** are used for the access credentials. Otherwise, if this member does not contain **DSBI_SIMPLEAUTHENTICATE**, the dialog uses the security context of the calling thread.

##### - dwFlags.DSBI_IGNORETREATASLEAF (4194304 (0x400000))

When determining if the object is displayed in the dialog box, the **treatAsLeaf** display specifier is ignored.

##### - dwFlags.DSBI_INCLUDEHIDDEN (131072 (0x20000))

Include hidden objects in the dialog box.

##### - dwFlags.DSBI_NOBUTTONS (1 (0x1))

The **+** and **-** buttons are not displayed in the dialog box.

##### - dwFlags.DSBI_NOLINES (2 (0x2))

The lines that connect the objects in the dialog box are not displayed.

##### - dwFlags.DSBI_NOLINESATROOT (4 (0x4))

The lines and buttons above the root objects are not displayed.

##### - dwFlags.DSBI_NOROOT (65536 (0x10000))

The root object, specified by **pszRoot**, is not displayed and the immediate child objects of the root are displayed at the root of the tree. This flag has no effect if **pszRoot** is **NULL** or if this member contains **DSBI_ENTIREDIRECTORY**.

##### - dwFlags.DSBI_RETURNOBJECTCLASS (16777216 (0x1000000))

Indicates that the **pszObjectClass** and **cchObjectClass** are valid and should be filled.

##### - dwFlags.DSBI_RETURN_FORMAT (1048576 (0x100000))

Indicates that the **dwReturnFormat** member is valid. If this flag is not set, the path format defaults to X.500.

##### - dwFlags.DSBI_SIMPLEAUTHENTICATE (8388608 (0x800000))

Indicates that secure authentication is not required when calling [ADsOpenObject](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsopenobject).

## See also

[ADS_FORMAT_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_format_enum)

[ADsOpenObject](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsopenobject)

[BFFCallBack](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nc-shlobj_core-bffcallback)

[DsBrowseForContainer](https://learn.microsoft.com/windows/desktop/api/dsclient/nf-dsclient-dsbrowseforcontainera)

## Remarks

> [!NOTE]
> The dsclient.h header defines DSBROWSEINFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).