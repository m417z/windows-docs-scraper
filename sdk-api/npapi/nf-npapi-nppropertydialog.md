# NPPropertyDialog function

## Description

Called when the user clicks a button added by using the **NPPropertyDialog** function. The **NPPropertyDialog** function is called only for file and directory network properties.

## Parameters

### `hwndParent` [in]

A handle to the parent window that should own the file property dialog box.

### `iButtonDlg` [in]

The index of the button that was pressed.

This index specifies which property dialog box was requested, starting with one for the first button returned from
the [NPGetPropertyText](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npgetpropertytext) function. If there are multiple file names selected, 10 is added to this number. In other words, if there is more than one file selected and the user presses the first provider-defined property button, *iButtonDlg* will be 11. If there is only one file selected and the user presses the second network property button, *iButtonDlg* will be two.

### `nPropSel` [in]

Specifies what items the property dialog box should act on. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **WNPS_FILE** | A single file. |
| **WNPS_DIR** | A single directory. |
| **WNPS_MULT** | A selection of multiple files, directories, or both. |

### `lpFileName` [in]

A pointer to the names of the items that the property dialog box should act on. The only supported items are files and directories, so the item names are file names. These should be unambiguous, contain no wildcard characters, and be fully qualified, for example, **C:\Local\\***Example***.doc**. Multiple file names should be separated with spaces. A file name that contains spaces can be enclosed in quotation marks, for example, **"C:\\***My File***"**. In this case, it is treated as a single name. A caret (^) can also be used as the quotation mechanism for single characters, for example, C:\My^"File and "C:\My^"File" both refer to the file C:\My"File.

### `nType` [in]

Specifies the item type, which must be WNTYPE_FILE.

## Return value

If the function succeeds, it returns WN_SUCCESS. If the function fails, it returns an error code. Call
[SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) to set this extended error code, which may include the following return codes.

| Return code | Description |
| --- | --- |
| **WN_BAD_VALUE** | One or more parameters is an unexpected form or value. |
| **WN_OUT_OF_MEMORY** | There is insufficient memory to display the dialog box. |
| **WN_NET_ERROR** | A network error occurred. |

## Remarks

This function is called only on sets of properties for which
[NPGetPropertyText](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npgetpropertytext) has assigned a button name.

This function is used in File Manager to view and modify the network properties (for example, permissions) for files on a network device. If this function is not supported, File Manager does not provide any default behavior.

In this version of the Network Provider interface, *lpFileName* can point to only file names. The network provider should return WN_BAD_VALUE if it sees an inappropriate device.

## See also

[NPGetPropertyText](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npgetpropertytext)

[SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror)