# NPGetPropertyText function

## Description

Retrieves the names of buttons to add to a property dialog box for a network resource.

## Parameters

### `iButton` [in]

Indicates the index of the button. File Manager supports a maximum of six buttons. This parameter is numbered 1-6 for each of the possible buttons if only one file is selected, or 11-16 if multiple files are selected.

### `nPropSel` [in]

Specifies what items the property dialog box focuses on. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **WNPS_FILE** | A single file. |
| **WNPS_DIR** | A single directory. |
| **WNPS_MULT** | A selection of multiple files, directories, or both. |

### `lpName` [in]

Pointer to a null-terminated string that contains the names of the item or items to be viewed or edited by means of the dialog box. The only supported items are files and directories, so the item names are file names. These should be unambiguous, contain no wildcard characters, and be fully qualified (for example, C:\LOCAL\EXAMPLE.DOC). Multiple file names should be separated with spaces. A file name that contains spaces may be surrounded by quotes (for example, "C:\My File"). In this case. it is treated as a single name. The caret character '^' may also be used as the quotation mechanism for single characters (for example, C:\My^"File, "C:\My^"File" both refer to the file C:\My"File).

### `lpButtonName` [out]

Pointer to a buffer where the network provider should copy the name of the property button. On success, the buffer pointed to by *lpButtonName* contains the name of the property button. If this buffer, on exit, contains the empty string, then the button corresponding to that name and all succeeding buttons will be removed from the dialog box. The network provider cannot "skip" a button.

### `nButtonNameLen` [in, out]

Specifies the size of the *lpButtonName* buffer in characters, including the terminating null character.

### `nType` [in]

Specifies the item type, which must be WNTYPE_FILE.

## Return value

If the function succeeds, it should return WN_SUCCESS and *lpButtonName* can be used. If it points to the empty string, no button corresponds to an index as high as *iButton*. If the return value is other than WN_SUCCESS, the provider should also call [SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) to set extended error information. Extended error codes include the following.

| Return code | Description |
| --- | --- |
| **WN_OUT_OF_MEMORY** | Could not load string from resources. |
| **WN_MORE_DATA** | The given buffer is too small to fit the text of the button. |
| **WN_BAD_VALUE** | The *lpName* parameter is an unexpected form. |
| **WN_NOT_SUPPORTED** | Property dialog boxes are not supported for the given object type, *nType*. |

## Remarks

File Manager calls this function each time the property dialog box is brought up, and it does this before displaying the dialog box. If the user clicks a button added through this function by the network provider,
the [NPPropertyDialog](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-nppropertydialog) function is called with the appropriate parameters.

Only File Manager calls **NPGetPropertyText**, and it uses this function for files and directories.