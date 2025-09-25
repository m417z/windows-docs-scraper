# IBackgroundCopyJob2::RemoveCredentials

## Description

Removes credentials from use. The credentials must match an existing target and scheme pair that you specified using the
[IBackgroundCopyJob2::SetCredentials](https://learn.microsoft.com/windows/desktop/api/bits1_5/nf-bits1_5-ibackgroundcopyjob2-setcredentials) method. There is no method to retrieve the credentials you have set.

## Parameters

### `Target` [in]

Identifies whether to use the credentials for proxy or server authentication.

### `Scheme` [in]

Identifies the authentication scheme to use (basic or one of several challenge-response schemes). For details, see the
[BG_AUTH_SCHEME](https://learn.microsoft.com/windows/desktop/api/bits1_5/ne-bits1_5-bg_auth_scheme) enumeration.

## Return value

This method returns the following return values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Success |
| **S_FALSE** | No credentials have been set using the given *Target* and *Scheme* pair. |

## See also

[BG_AUTH_SCHEME](https://learn.microsoft.com/windows/desktop/api/bits1_5/ne-bits1_5-bg_auth_scheme)

[BG_AUTH_TARGET](https://learn.microsoft.com/windows/desktop/api/bits1_5/ne-bits1_5-bg_auth_target)

[IBackgroundCopyJob2::SetCredentials](https://learn.microsoft.com/windows/desktop/api/bits1_5/nf-bits1_5-ibackgroundcopyjob2-setcredentials)