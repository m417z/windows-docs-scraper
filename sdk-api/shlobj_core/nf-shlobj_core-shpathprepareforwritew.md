# SHPathPrepareForWriteW function

## Description

Checks to see if the path exists. This includes remounting mapped network drives, prompting for ejectable media to be reinserted, creating the paths, prompting for the media to be formatted, and providing the appropriate user interfaces, if necessary. Read/write permissions for the medium are not checked.

## Parameters

### `hwnd` [in, optional]

Type: **HWND**

A handle to a window that specifies the parent window to be used for any user interface windows that must be created. If set to **NULL**, user interface windows are not created.

### `punkEnableModless` [in, optional]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface that specifies the [IOleInPlaceActiveObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplaceactiveobject) object that implements the [EnableModeless](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellview-enablemodeless) method.

### `pszPath` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string of maximum length MAX_PATH that specifies the path to be verified as valid for writing. This can be a UNC or file drive path.

### `dwFlags`

Type: **DWORD**

Flags that determine behavior options. This parameter can be a combination of the following values.

#### SHPPFW_NONE

Do not create new directories.

#### SHPPFW_DEFAULT

Default. Do not prompt the user if a directory needs to be created. This is identical to **SHPPFW_DIRCREATE**. Do not pass with **SHPPFW_ASKDIRCREATE**.

#### SHPPFW_DIRCREATE

Create directories without prompting the user. Do not pass with **SHPPFW_ASKDIRCREATE**.

#### SHPPFW_ASKDIRCREATE

Prompt the user before creating directories. Do not pass with **SHPPFW_DIRCREATE**.

#### SHPPFW_IGNOREFILENAME

Last item in *pszPath* is a file name, so ignore. For example, if *pszPath*="C:\MyDir\MyFile.doc", only use "C:\MyDir". If *pszPath*="C:\MyFirDir\MySecDir", only use "C:\MyFirDir".

#### SHPPFW_NOWRITECHECK

Not currently implemented.

#### SHPPFW_MEDIACHECKONLY

**Windows XP or later.** Suppresses the "not accessible" error message box, which displays when a failure other than a user cancellation occurs, and *hwnd* is not **NULL**.

##### - dwFlags.SHPPFW_ASKDIRCREATE

Prompt the user before creating directories. Do not pass with **SHPPFW_DIRCREATE**.

##### - dwFlags.SHPPFW_DEFAULT

Default. Do not prompt the user if a directory needs to be created. This is identical to **SHPPFW_DIRCREATE**. Do not pass with **SHPPFW_ASKDIRCREATE**.

##### - dwFlags.SHPPFW_DIRCREATE

Create directories without prompting the user. Do not pass with **SHPPFW_ASKDIRCREATE**.

##### - dwFlags.SHPPFW_IGNOREFILENAME

Last item in *pszPath* is a file name, so ignore. For example, if *pszPath*="C:\MyDir\MyFile.doc", only use "C:\MyDir". If *pszPath*="C:\MyFirDir\MySecDir", only use "C:\MyFirDir".

##### - dwFlags.SHPPFW_MEDIACHECKONLY

**Windows XP or later.** Suppresses the "not accessible" error message box, which displays when a failure other than a user cancellation occurs, and *hwnd* is not **NULL**.

##### - dwFlags.SHPPFW_NONE

Do not create new directories.

##### - dwFlags.SHPPFW_NOWRITECHECK

Not currently implemented.

## Return value

Type: **HRESULT**

Returns S_OK if the path is available, or an error code otherwise. Note that a return value of S_OK does not mean that the medium is writable; it simply means that the path is available.

## Remarks

The primary use of this function is for a program to check a path before using it and display the necessary user interface to prompt the user. For example, if the disk in drive A: were missing, a window that prompts the user to insert the disk would appear.

> [!NOTE]
> The shlobj_core.h header defines SHPathPrepareForWrite as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).