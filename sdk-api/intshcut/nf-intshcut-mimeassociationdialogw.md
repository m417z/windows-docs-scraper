# MIMEAssociationDialogW function

## Description

Runs the unregistered MIME content type dialog box.

**Note** Windows XP Service Pack 2 (SP2) or later: This function is no longer supported.

## Parameters

### `hwndParent`

Type: **HWND**

A handle to the parent window of any posted child windows.

### `dwInFlags`

Type: **DWORD**

A bit flag value that specifies if an association is to be registered. The bit flag is the value MIMEASSOCDLG_FL_REGISTER_ASSOC (0x0001). If this bit is set, the selected application is registered as the handler for the given MIME type. If this bit is clear, no association is registered.

An application is registered only if this flag is set and the user indicates that a persistent association is to be made.

Registration is impossible if the string at *pcszFile* does not contain an extension.

### `pcszFile`

Type: **PCTSTR**

The address of a null-terminated string that contains the name of the target file. This file must conform to the content type described by the *pcszMIMEContentType* parameter.

### `pcszMIMEContentType`

Type: **PCTSTR**

The address of a null-terminated string that contains the unregistered content type.

### `pszAppBuf` [out]

Type: **PTSTR**

A pointer to a buffer that, when this function returns successfully, receives the path of the application specified by the user.

### `ucAppBufLen`

Type: **UINT**

Size of *pszAppBuf*, in characters.

## Return value

Type: **HRESULT**

**Note** As of Windows XP SP2, this function is not supported and returns E_NOTIMPL in all situations.

In supported systems, returns S_OK if the content type was successfully associated with the extension. In this case, the extension is associated as the default for the content type, and *pszAppBuf* points to the string that contains the path of the specified application. The function returns S_FALSE if nothing was registered. Otherwise, the return value will be one of the following:

| Return code | Description |
| --- | --- |
| **E_ABORT** | The user canceled the operation. |
| **E_FLAGS** | The flag combination passed in *dwInFlags* is invalid. |
| **E_OUTOFMEMORY** | There was insufficient memory available to complete the operation. |
| **E_POINTER** | One of the input pointers is invalid. |

## Remarks

This function does not validate the syntax of the input content type string at *pcszMIMEContentType*. A successful return value does not indicate that the specified MIME content type is valid.

> [!NOTE]
> The intshcut.h header defines MIMEAssociationDialog as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).