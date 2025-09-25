# FormatApplicationUserModelId function

## Description

Constructs an [application user model ID](https://learn.microsoft.com/windows/desktop/appxpkg/appx-packaging-glossary) from the *package family name* and the *package relative application ID* (PRAID).

## Parameters

### `packageFamilyName` [in]

Type: **PCWSTR**

The package family name.

### `packageRelativeApplicationId` [in]

Type: **PCWSTR**

The package-relative app ID (PRAID).

### `applicationUserModelIdLength` [in, out]

Type: **UINT32***

A pointer to a variable that holds the number of characters (**WCHAR**s) in the app user model ID string, which includes the null-terminator.

First you pass **NULL** to *applicationUserModelId* to get the number of characters. You use this number to allocate memory space for *applicationUserModelId*. Then you pass the address of this memory space to fill *applicationUserModelId*.

### `applicationUserModelId` [out, optional]

Type: **PWSTR**

A pointer to memory space that receives the app user model ID string, which includes the null-terminator.

## Return value

Type: **LONG**

If the function succeeds it returns **ERROR_SUCCESS**. Otherwise, the function returns an error code. The possible error codes include the following.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *packageFamilyName* or *packageRelativeApplicationId* parameter isn't valid. |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer specified by *applicationUserModelId* is not large enough to hold the data; the required buffer size, in **WCHAR**s, is stored in the variable pointed to by *applicationUserModelIdLength*. |