# SrpGetEnterpriseIds function

## Description

**Note** Windows Information Protection (WIP) policy cannot be applied on Windows 10, version 1511 (build 10586) or earlier.

Gets the list of enterprise identifiers for the given token.

The enterprise IDs are returned only for those applications explicitly allowed by management.

## Parameters

### `tokenHandle` [in]

Token Handle to be checked.

### `numberOfBytes` [in, out, optional]

If *enterpriseIds* is provided, then this supplies the size of the *enterpriseIds* buffer. If you provide a buffer size, and it's too small, the output will contain the required size of the *enterpriseIds* buffer.

### `enterpriseIds` [out, optional]

An array of enterprise ID string pointers.

### `enterpriseIdCount` [out]

The enterprise ID count on the token. Zero if the token is not explicitly enterprise allowed.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

If this function does not provide any enterprise IDs, it returns **E_NOT_SUFFICIENT_BUFFER**.