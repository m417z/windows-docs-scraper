# WdsTransportProviderCompareContent function

## Description

Compares a specified content name and instance to an open content stream to determine if they are the same.

## Parameters

### `hInstance` [in]

Handle to an instance against which this content will be opened.

### `pwszContentName` [in]

The name of the content to compare.

### `hContent` [in]

Handle to a open content stream.

### `pbContentMatches` [out]

If the content stream identified to by *hInstance* and *pwszContentName* is exactly the same as the content stream specified by *hContent*, the location receives a true value. Otherwise, the location receives a false value.

## Return value

If the function succeeds, the return is **S_OK**.

## Remarks

This callback is required.