# IWbemPath::SetText

## Description

The
**IWbemPath::SetText** method parses a path so that information on the path can be returned by the path parser. Typically, this is the first method called by users of the interface. The only case in which this is not the first method called is when the calling code is constructing the path by specifying each piece separately.

## Parameters

### `uMode` [in]

Flag specifying the type of paths accepted.

#### WBEMPATH_CREATE_ACCEPT_RELATIVE

Allow paths without server names.

#### WBEMPATH_CREATE_ACCEPT_ABSOLUTE

Reserved for future use.

#### WBEMPATH_CREATE_ACCEPT_ALL

Allow setting an empty path (which additionally clears out the object), Also allows paths which have just the server names, or paths which don't have server names.

#### WBEMPATH_TREAT_SINGLE_IDENT_AS_NS

A simple path, such as "XYZ" is interpreted as a namespace.

### `pszPath` [in]

Path to be parsed.

## Return value

This method returns an **HRESULT** indicating the status of the method call.

## See also

[IWbemPath](https://learn.microsoft.com/windows/desktop/api/wmiutils/nn-wmiutils-iwbempath)