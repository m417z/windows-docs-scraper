# MsiGetUserInfoA function

## Description

The
**MsiGetUserInfo** function returns the registered user information for an installed product.

## Parameters

### `szProduct` [in]

Specifies the product code for the product to be queried.

### `lpUserNameBuf` [out]

Pointer to a variable that receives the name of the user.

### `pcchUserNameBuf` [in, out]

Pointer to a variable that specifies the size, in characters, of the buffer pointed to by the *lpUserNameBuf* parameter. This size should include the terminating null character.

### `lpOrgNameBuf` [out]

Pointer to a buffer that receives the organization name.

### `pcchOrgNameBuf` [in, out]

Pointer to a variable that specifies the size, in characters, of the buffer pointed to by the *lpOrgNameBuf* parameter. On input, this is the full size of the buffer, including a space for a terminating null character. If the buffer passed in is too small, the count returned does not include the terminating null character.

### `lpSerialBuf` [in]

Pointer to a buffer that receives the product ID.

### `pcchSerialBuf` [in, out]

Pointer to a variable that specifies the size, in characters, of the buffer pointed to by the *lpSerialBuf* parameter. On input, this is the full size of the buffer, including a space for a terminating null character. If the buffer passed in is too small, the count returned does not include the terminating null character.

## Return value

| Value | Meaning |
| --- | --- |
| **USERINFOSTATE_ABSENT** | Some or all of the user information is absent. |
| **USERINFOSTATE_INVALIDARG** | One of the function parameters was invalid. |
| **USERINFOSTATE_MOREDATA** | A buffer is too small to hold the requested data. |
| **USERINFOSTATE_PRESENT** | The function completed successfully. |
| **USERINFOSTATE_UNKNOWN** | The product code does not identify a known product. |

## Remarks

When the
**MsiGetUserInfo** function returns, the *pcchNameBuf* parameter contains the length of the class string stored in the buffer. The count returned does not include the terminating null character. If the buffer is not big enough, the
**MsiGetUserInfo** function returns USERINFOSTATE_MOREDATA, and
**MsiGetUserInfo** contains the size of the string, in characters, without counting the null character.

The user information is considered to be present even in the absence of a company name.

> [!NOTE]
> The msi.h header defines MsiGetUserInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[System Status Functions](https://learn.microsoft.com/windows/desktop/Msi/installer-function-reference)