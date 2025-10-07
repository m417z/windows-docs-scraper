# IQueryAssociations::Init

## Description

Initializes the [IQueryAssociations](https://learn.microsoft.com/windows/desktop/api/shlwapi/nn-shlwapi-iqueryassociations) interface and sets the root key to the appropriate ProgID.

## Parameters

### `flags` [in]

Type: **[ASSOCF](https://learn.microsoft.com/windows/win32/shell/assocf_str)**

A flag that specifies how the search is to be initialized. It is typically set to zero, but it can also take one of the following [ASSOCF](https://learn.microsoft.com/windows/win32/shell/assocf_str) values.

* [ASSOCF_INIT_BYEXENAME](https://learn.microsoft.com/windows/win32/shell/assocf_str)
* [ASSOCF_INIT_DEFAULTTOFOLDER](https://learn.microsoft.com/windows/win32/shell/assocf_str)
* [ASSOCF_INIT_DEFAULTTOSTAR](https://learn.microsoft.com/windows/win32/shell/assocf_str)

### `pszAssoc` [in, optional]

Type: **LPCWSTR**

A Unicode string that is used to determine the root key. If a value is specified for *hkProgid*, set this parameter to **NULL**. Four types of string can be used:

#### File name extension

A file name extension, such as .txt.

#### CLSID

A CLSID GUID in the standard "{GUID}" format.

#### ProgID

An application's ProgID, such as **Word.Document.8**.

#### Executable name

The name of an application's .exe file. The [ASSOCF_OPEN_BYEXENAME](https://learn.microsoft.com/windows/win32/shell/assocf_str) flag must be set in *flags*.

### `hkProgid` [in, optional]

Type: **HKEY**

The HKEY value of the subkey that is used as a root key. The search looks only below this key. If a value is specified for *pwszAssoc*, set this parameter to **NULL**.

### `hwnd` [in, optional]

Type: **HWND**

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method initializes the interface, and is also called each time you need to specify a new root key. You can use *pwszAssoc* to specify a string, such as a file name extension or its associated ProgID, that identifies the root key. You can also specify the root key's HKEY value. **Init** will then use this information to locate the root key in the registry. Subsequent calls to the other [IQueryAssociations](https://learn.microsoft.com/windows/desktop/api/shlwapi/nn-shlwapi-iqueryassociations) methods will use it as their starting point and search for the information in the root key's subkeys.

## See also

[IQueryAssociations](https://learn.microsoft.com/windows/desktop/api/shlwapi/nn-shlwapi-iqueryassociations)