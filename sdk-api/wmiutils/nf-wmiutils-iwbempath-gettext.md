# IWbemPath::GetText

## Description

The
**IWbemPath::GetText** method returns a textual representation of a path that has previously been placed into a parser object.

## Parameters

### `lFlags` [in]

Flag which controls how the text is returned.

#### WBEMPATH_COMPRESSED

Obsolete. Do not use.

#### WBEMPATH_GET_RELATIVE_ONLY

Returns the relative path, skips server and namespaces.

#### WBEMPATH_GET_SERVER_TOO

Returns the entire path, including server and namespace.

#### WBEMPATH_GET_SERVER_AND_NAMESPACE_ONLY

Returns only the server and namespace portion of the path. Ignores the class or key portion.

#### WBEMPATH_GET_NAMESPACE_ONLY

Returns only the namespace portion of the path.

#### WBEMPATH_GET_ORIGINAL

Returns whatever was passed in using
[SetText](https://learn.microsoft.com/windows/desktop/api/wmiutils/nf-wmiutils-iwbempath-settext) method.

### `puBuffLength` [in, out]

Caller sets this to the size of *pszText*. If the method is successful, it sets *puBufferLength* to the number of wide characters used, including the terminating null character.

### `pszText` [in, out]

Textual representation of the path.

## Return value

This method returns the following values.

## See also

[IWbemPath](https://learn.microsoft.com/windows/desktop/api/wmiutils/nn-wmiutils-iwbempath)