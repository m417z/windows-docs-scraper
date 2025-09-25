# GetPackagesByPackageFamily function

## Description

Gets the packages with the specified family name for the current user.

## Parameters

### `packageFamilyName` [in]

Type: **PCWSTR**

The package family name.

### `count` [in, out]

Type: **UINT32***

A pointer to a variable that holds the number of package full names.

First you pass **NULL** to *packageFullNames* to get the number of package full names. You use this number to allocate memory space for *packageFullNames*. Then you pass the address of this number to fill *packageFullNames*.

### `packageFullNames` [out, optional]

Type: **PWSTR***

A pointer to the strings of package full names.

### `bufferLength` [in, out]

Type: **UINT32***

A pointer to a variable that holds the number of characters in the string of package full names.

First you pass **NULL** to *buffer* to get the number of characters. You use this number to allocate memory space for *buffer*. Then you pass the address of this number to fill *buffer*.

### `buffer` [out, optional]

Type: **WCHAR***

The string of characters for all of the package full names.

## Return value

Type: **LONG**

If the function succeeds it returns **ERROR_SUCCESS**. Otherwise, the function returns an error code. The possible error codes include the following.

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | One or more buffer is not large enough to hold the data. The required size is specified by either *count* or *buffer*. |

## See also

[PackageNameAndPublisherIdFromFamilyName](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-packagenameandpublisheridfromfamilyname)