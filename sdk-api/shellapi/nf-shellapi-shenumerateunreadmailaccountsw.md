# SHEnumerateUnreadMailAccountsW function

## Description

Enumerates the user accounts that have unread email.

## Parameters

### `hKeyUser` [in, optional]

Type: **HKEY**

A valid HKEY for a given user.

### `dwIndex`

Type: **DWORD**

The index of the user account.

### `pszMailAddress` [out]

Type: **LPTSTR**

A pointer to a Unicode string that specifies the email address of an account belonging to the specified user.

### `cchMailAddress`

Type: **int**

The number of characters in the email address.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The *hKeyUser* parameter is the HKEY for the root of the user's information, for example **HKEY_CURRENT_USER**, or any key enumerated under **HKEY_USERS**.

> [!NOTE]
> The shellapi.h header defines SHEnumerateUnreadMailAccounts as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).