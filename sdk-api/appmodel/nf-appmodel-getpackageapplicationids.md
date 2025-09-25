# GetPackageApplicationIds function

## Description

Gets the IDs of apps in the specified package.

## Parameters

### `packageInfoReference` [in]

Type: **PACKAGE_INFO_REFERENCE**

A reference to package information.

### `bufferLength` [in, out]

Type: **UINT32***

A pointer to a variable that holds the size of *buffer*, in bytes.

First you pass **NULL** to *buffer* to get the required size of *buffer*. You use this number to allocate memory space for *buffer*. Then you pass the address of this memory space to fill *buffer*.

### `buffer` [out, optional]

Type: **BYTE***

A pointer to memory space that receives the app IDs.

### `count` [out, optional]

Type: **UINT32***

A pointer to a variable that receives the number of app IDs in *buffer*.

## Return value

Type: **LONG**

If the function succeeds it returns **ERROR_SUCCESS**. Otherwise, the function returns an error code. The possible error codes include the following.

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer is not large enough to hold the data. The required size is specified by *bufferLength*. |