# BG_AUTH_CREDENTIALS structure

## Description

Identifies the target (proxy or server), authentication scheme, and the user's credentials to use for user authentication requests. The structure is passed to the
[IBackgroundCopyJob2::SetCredentials](https://learn.microsoft.com/windows/desktop/api/bits1_5/nf-bits1_5-ibackgroundcopyjob2-setcredentials) method.

## Members

### `Target`

Identifies whether to use the credentials for a proxy or server authentication request. For a list of values, see the
[BG_AUTH_TARGET](https://learn.microsoft.com/windows/desktop/api/bits1_5/ne-bits1_5-bg_auth_target) enumeration. You can specify only one value.

### `Scheme`

Identifies the scheme to use for authentication (for example, Basic or NTLM). For a list of values, see the
[BG_AUTH_SCHEME](https://learn.microsoft.com/windows/desktop/api/bits1_5/ne-bits1_5-bg_auth_scheme) enumeration. You can specify only one value.

### `Credentials`

Identifies the credentials to use for the specified authentication scheme. For details, see the
[BG_AUTH_CREDENTIALS_UNION](https://learn.microsoft.com/windows/desktop/api/bits1_5/ns-bits1_5-bg_auth_credentials_union) union.

## See also

[BG_AUTH_CREDENTIALS_UNION](https://learn.microsoft.com/windows/desktop/api/bits1_5/ns-bits1_5-bg_auth_credentials_union)

[BG_AUTH_SCHEME](https://learn.microsoft.com/windows/desktop/api/bits1_5/ne-bits1_5-bg_auth_scheme)

[BG_AUTH_TARGET](https://learn.microsoft.com/windows/desktop/api/bits1_5/ne-bits1_5-bg_auth_target)

[IBackgroundCopyJob2::SetCredentials](https://learn.microsoft.com/windows/desktop/api/bits1_5/nf-bits1_5-ibackgroundcopyjob2-setcredentials)