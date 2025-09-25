# DnsAcquireContextHandle_A function

## Description

The
**DnsAcquireContextHandle** function type acquires a context handle to a set of credentials. Like many DNS functions, the
**DnsAcquireContextHandle** function type is implemented in multiple forms to facilitate different character encoding. Based on the character encoding involved, use one of the following functions:

* **DnsAcquireContextHandle_A** (_A for ANSI encoding)
* **DnsAcquireContextHandle_W** (_W for Unicode encoding)

## Parameters

### `CredentialFlags` [in]

A flag that indicates the character encoding. Set to **TRUE** for Unicode, **FALSE** for ANSI.

### `Credentials` [in, optional]

A pointer to a [SEC_WINNT_AUTH_IDENTITY_W](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-sec_winnt_auth_identity_a) structure or a **SEC_WINNT_AUTH_IDENTITY_A** structure that contains the name, domain, and password of the account to be used in a secure dynamic update. If *CredentialFlags* is set to **TRUE**, *Credentials* points to a **SEC_WINNT_AUTH_IDENTITY_W** structure; otherwise, *Credentials* points to a **SEC_WINNT_AUTH_IDENTITY_A** structure. If not specified, the credentials of the calling service are used. This parameter is optional.

### `pContext` [out]

A pointer to a handle pointing to the returned credentials.

## Return value

Returns success confirmation upon successful completion. Otherwise, returns the appropriate DNS-specific error code as defined in Winerror.h.

## See also

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)

[DnsQuery](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsquery_a)

[SEC_WINNT_AUTH_IDENTITY](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-sec_winnt_auth_identity_a)