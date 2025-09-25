# IUserAccountChangeCallback::OnPictureChange

## Description

Called to send notifications when the picture that represents a user account is changed.

## Parameters

### `pszUserName` [in]

Type: **LPCWSTR**

Pointer to a string that contains the user name. Set this parameter to **NULL** to specify the current user.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When the picture that represents a user account changes, the callback object notifies all applications that are registered under this registry subkey:

```
HKEY_LOCAL_MACHINE
   SOFTWARE
      Microsoft
         Windows
            CurrentVersion
               UserPictureChange
```