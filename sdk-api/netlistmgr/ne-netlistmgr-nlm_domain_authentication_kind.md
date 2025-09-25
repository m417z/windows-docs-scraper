## Description

Defines constants that specify a domain authentication method.

Only one of the listed constants is set for any instance of **DomainAuthenticationKind**. In some scenarios, the constant set will represent the most preferred protocol used to determine whether the domain was authenticated.

## Constants

### `NLM_DOMAIN_AUTHENTICATION_KIND_NONE`

Specifies no domain authentication method; and/or that the network couldn't be domain-authenticated.

### `NLM_DOMAIN_AUTHENTICATION_KIND_LDAP`

Specifies the domain authentication method for an Active Directory network; and/or that the machine was successful in a Lightweight Directory Access Protocol (LDAP) authentication request against the configured Active Directory servers on the current network.

### `NLM_DOMAIN_AUTHENTICATION_KIND_TLS`

Specifies the Transport Layer Security (TLS) domain authentication method; and/or that the network connection was able to successfully complete a HTTPS connection with verified TLS authentication to an endpoint configured by the `AllowedTlsAuthenticationEndpoints` Mobile Device Management (MDM) policy.

## Remarks

## See also

* [INetwork2::IsDomainAuthenticatedBy method](https://learn.microsoft.com/windows/win32/api/netlistmgr/nf-netlistmgr-inetwork2-isdomainauthenticatedby)
* [INetworkConnection2::IsDomainAuthenticatedBy method](https://learn.microsoft.com/windows/win32/api/netlistmgr/nf-netlistmgr-inetworkconnection2-isdomainauthenticatedby)