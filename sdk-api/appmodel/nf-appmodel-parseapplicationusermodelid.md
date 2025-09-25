# ParseApplicationUserModelId function

## Description

Deconstructs an [application user model ID](https://learn.microsoft.com/windows/desktop/appxpkg/appx-packaging-glossary) to its *package family name* and *package relative application ID* (PRAID).

## Parameters

### `applicationUserModelId` [in]

Type: **PCWSTR**

The app user model ID.

### `packageFamilyNameLength` [in, out]

Type: **UINT32***

A pointer to a variable that holds the number of characters (**WCHAR**s) in the package family name string, which includes the null-terminator.

First you pass **NULL** to *packageFamilyName* to get the number of characters. You use this number to allocate memory space for *packageFamilyName*. Then you pass the address of this memory space to fill *packageFamilyName*.

### `packageFamilyName` [out, optional]

Type: **PWSTR**

A pointer to memory space that receives the package family name string, which includes the null-terminator.

### `packageRelativeApplicationIdLength` [in, out]

Type: **UINT32***

A pointer to a variable that holds the number of characters (**WCHAR**s) in the package-relative app ID string, which includes the null-terminator.

First you pass **NULL** to *packageRelativeApplicationId* to get the number of characters. You use this number to allocate memory space for *packageRelativeApplicationId*. Then you pass the address of this memory space to fill *packageRelativeApplicationId*.

### `packageRelativeApplicationId` [out, optional]

Type: **PWSTR**

A pointer to memory space that receives the package-relative app ID (PRAID) string, which includes the null-terminator.

## Return value

Type: **LONG**

If the function succeeds it returns **ERROR_SUCCESS**. Otherwise, the function returns an error code. The possible error codes include the following.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *applicationUserModelId* parameter isn't valid. |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer specified by *packageFamilyName* or *packageRelativeApplicationId* is not large enough to hold the data; the required buffer size, in **WCHAR**s, is stored in the variable pointed to by *packageFamilyNameLength* or *packageRelativeApplicationIdLength*. |