# DeleteConnectedIdentity function

Deletes the user credential used for the connected identity.

## Parameters

*ProviderHandle* \[in\]

Identity provider handle.

*UserToken* \[in, optional\]

Token of the connected user whose account is going to be converted to a local account. If *UserToken* is not **NULL**, the identity provider uses this token to load the user profile and clean up connected states. If *UserToken* is **NULL**, LSA is forcing the disconnection. The identity provider should clean up any global connected states on this user, but the provider does not have to clean up connected states in the user profile.

*UserSid* \[in\]

The primary SID of the connected user. If *UserToken* is not **NULL**, this parameter is the user SID of the token. If *UserToken* is **NULL**, this parameter is used to identify the connected user and clean up global connected states of that user.

*IdentityUserName* \[in\]

The user name of the identity.

## Return value

If the function succeeds, the function returns SEC\_E\_OK.

If the function fails, the function may return one of the following error codes.

| Return value | Description |
|------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------|
| STATUS\_INVALID\_PARAMETER | A parameter is not valid.<br> |
| STATUS\_NO\_SUCH\_USER | The user identified by *UserSid* does not exist, is not currently connected, or there is no identity whose user name matches *IdentityUserName*.<br> |
| STATUS\_INSUFFICIENT\_RESOURCES | There is not enough memory to process the request.<br> |

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | Indentitystore.h |

