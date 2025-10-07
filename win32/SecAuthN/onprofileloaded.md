# OnProfileLoaded function

Checks that the online user profile is loaded.

## Parameters

*ProviderHandle* \[in\]

The provider handle.

*UserToken* \[in\]

Token of the user whose profile is being loaded or unloaded.

*Loaded* \[in\]

**TRUE** if the profile has been loaded.

## Return value

If the function succeeds, the function returns STATUS\_SUCCESS.

If the function fails, the function returns a nonzero error code that is a provider-specific error for diagnostic purposes.

## Remarks

This function is called each time the [**LoadUserProfile**](https://learn.microsoft.com/windows/win32/api/userenv/nf-userenv-loaduserprofilea) function is called. It is not synchronized with **LoadUserProfile**; that is, **LoadUserProfile** might have returned and the profile might have been unloaded by the time the function was called. This function can be called more than once even when the profile has been loaded. The identity provider must not assume that a call to this function with *Loaded* equal to TRUE will be followed by a call with *Loaded* equal to FALSE.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | Lsaidprov.h |

