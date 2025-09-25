## Description

Queries whether the specified domain authentication method succeeded for this network connection.

## Parameters

### `domainAuthenticationKind`

Type: \[in\] **[NLM_DOMAIN_AUTHENTICATION_KIND](https://learn.microsoft.com/windows/win32/api/netlistmgr/ne-netlistmgr-nlm_domain_authentication_kind)**

The specific domain authentication method to query about.

### `pValue`

Type: \[out, retval\] **[BOOL](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

The function dereferences *pValue*, and assigns `TRUE` if this network connection has the same domain authentication kind as that specified in the *domainAuthenticationKind* parameter; or `FALSE` if this network connection has a different domain authentication kind from that specified in *domainAuthenticationKind*.

## Return value

Returns **S_OK** if successful.

## Remarks

See **Remarks** for [INetwork2::IsDomainAuthenticatedBy method](https://learn.microsoft.com/windows/win32/api/netlistmgr/nf-netlistmgr-inetwork2-isdomainauthenticatedby).

## Example

See **Example** for [INetwork2::IsDomainAuthenticatedBy method](https://learn.microsoft.com/windows/win32/api/netlistmgr/nf-netlistmgr-inetwork2-isdomainauthenticatedby).

## See also

* [INetwork2::IsDomainAuthenticatedBy method](https://learn.microsoft.com/windows/win32/api/netlistmgr/nf-netlistmgr-inetwork2-isdomainauthenticatedby)