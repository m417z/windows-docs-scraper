# IDsBrowseDomainTree::FlushCachedDomains

## Description

The **IDsBrowseDomainTree::FlushCachedDomains** method frees the cached domain list.

## Return value

Returns a standard **HRESULT** value including the following.

## Remarks

This method frees the internal cached domain data. This method must be called before calling
[IDsBrowseDomainTree::SetComputer](https://learn.microsoft.com/windows/desktop/api/dsclient/nf-dsclient-idsbrowsedomaintree-setcomputer) to retarget to a computer of a different domain.

## See also

[IDsBrowseDomainTree](https://learn.microsoft.com/windows/desktop/api/dsclient/nn-dsclient-idsbrowsedomaintree)

[IDsBrowseDomainTree::SetComputer](https://learn.microsoft.com/windows/desktop/api/dsclient/nf-dsclient-idsbrowsedomaintree-setcomputer)