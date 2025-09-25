# FindPackagesByPackageFamily function

## Description

Finds the packages with the specified family name for the current user.

## Parameters

### `packageFamilyName` [in]

Type: **PCWSTR**

The package family name.

### `packageFilters` [in]

Type: **UINT32**

The [package constants](https://learn.microsoft.com/windows/desktop/appxpkg/package-constants) that specify how package information is retrieved. All package constants except **PACKAGE_FILTER_ALL_LOADED** are supported.

### `count` [in, out]

Type: **UINT32***

A pointer to a variable that holds the number of package full names that were found.

First you pass **NULL** to *packageFullNames* to get the number of package full names that were found. You use this number to allocate memory space for *packageFullNames*. Then you pass the address of this memory space to fill *packageFullNames*.

### `packageFullNames` [out, optional]

Type: **PWSTR***

A pointer to memory space that receives the strings of package full names that were found.

### `bufferLength` [in, out]

Type: **UINT32***

A pointer to a variable that holds the number of characters in the string of package full names.

First you pass **NULL** to *buffer* to get the number of characters. You use this number to allocate memory space for *buffer*. Then you pass the address of this memory space to fill *buffer*.

### `buffer` [out, optional]

Type: **WCHAR***

A pointer to memory space that receives the string of characters for all of the package full names.

### `packageProperties` [out, optional]

Type: **UINT32***

A pointer to memory space that receives the [package properties](https://learn.microsoft.com/windows/desktop/appxpkg/package-constants) for all of the packages that were found.

## Return value

Type: **LONG**

If the function succeeds it returns **ERROR_SUCCESS**. Otherwise, the function returns an error code. The possible error codes include the following.

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | One or more buffer is not large enough to hold the data. The required size is specified by either *count* or *buffer*. |