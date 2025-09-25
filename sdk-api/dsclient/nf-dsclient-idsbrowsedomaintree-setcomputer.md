# IDsBrowseDomainTree::SetComputer

## Description

The **IDsBrowseDomainTree::SetComputer** method specifies the computer and credentials to be used by this instance of the [IDsBrowseDomainTree](https://learn.microsoft.com/windows/desktop/api/dsclient/nn-dsclient-idsbrowsedomaintree) interface.

## Parameters

### `pszComputerName` [in]

Pointer to a null-terminated Unicode string that contains the name of the target computer.

### `pszUserName` [in]

Pointer to a null-terminated Unicode string that contains the user name used to access the computer.

### `pszPassword` [in]

Pointer to a null-terminated Unicode string that contains the password used to access the computer.

## Return value

Returns a standard **HRESULT** value including the following.

## Remarks

If this method is not called, the local host is assumed as the default computer.

When **SetComputer** is called on a particular [IDsBrowseDomainTree](https://learn.microsoft.com/windows/desktop/api/dsclient/nn-dsclient-idsbrowsedomaintree) instance, [IDsBrowseDomainTree::FlushCachedDomains](https://learn.microsoft.com/windows/desktop/api/dsclient/nf-dsclient-idsbrowsedomaintree-flushcacheddomains) must be called before **SetComputer** is called again.

## See also

[IDsBrowseDomainTree](https://learn.microsoft.com/windows/desktop/api/dsclient/nn-dsclient-idsbrowsedomaintree)

[IDsBrowseDomainTree::FlushCachedDomains](https://learn.microsoft.com/windows/desktop/api/dsclient/nf-dsclient-idsbrowsedomaintree-flushcacheddomains)