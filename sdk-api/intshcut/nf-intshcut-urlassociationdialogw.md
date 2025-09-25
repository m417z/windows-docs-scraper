# URLAssociationDialogW function

## Description

Invokes the unregistered URL protocol dialog box. This dialog box allows the user to select an application to associate with a previously unknown protocol.

**Note** Windows XP Service Pack 2 (SP2) or later: This function is no longer supported.

## Parameters

### `hwndParent`

Type: **HWND**

A handle to the parent window.

### `dwInFlags`

Type: **DWORD**

The bit flags that specify the behavior of the function. This value can be a combination of the following:

#### URLASSOCDLG_FL_USE_DEFAULT_NAME

Use the default file name (that is, "Internet Shortcut").

#### URLASSOCDLG_FL_REGISTER_ASSOC

Register the selected application as the handler for the protocol specified in *pcszURL*. The application is registered only if this flag is set and the user indicates that a persistent association is desired.

### `pcszFile`

Type: **PTCSTR**

The address of a constant zero-terminated string that contains the file name to associate with the URLs protocol.

### `pcszURL`

Type: **PTCSTR**

The address of a constant zero-terminated string that contains the URL with an unknown protocol.

### `pszAppBuf` [out]

Type: **PTSTR**

The address of a buffer that receives the path of the application specified by the user.

### `ucAppBufLen`

Type: **UINT**

The size of *pszAppBuf*, in characters.

##### - dwInFlags.URLASSOCDLG_FL_REGISTER_ASSOC

Register the selected application as the handler for the protocol specified in *pcszURL*. The application is registered only if this flag is set and the user indicates that a persistent association is desired.

##### - dwInFlags.URLASSOCDLG_FL_USE_DEFAULT_NAME

Use the default file name (that is, "Internet Shortcut").

## Return value

Type: **HRESULT**

**Note** As of Windows XP SP2, this function not supported and returns E_NOTIMPL in all situations.

In supported systems, returns S_OK if the application is registered with the URL protocol, or S_FALSE if nothing is registered. For example, the function returns S_FALSE when the user elects to perform a one-time execution via the selected application.

## Remarks

> [!NOTE]
> The intshcut.h header defines URLAssociationDialog as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).