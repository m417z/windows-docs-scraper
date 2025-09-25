# VectorFromBstr function

## Description

Returns a vector, assigning each character in the BSTR to an element of the vector.

## Parameters

### `bstr` [in]

The BSTR to be converted to a vector.

### `ppsa` [out]

A one-dimensional safearray containing the characters in the BSTR.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_OUTOFMEMORY** | Out of memory. |
| **E_INVALIDARG** | The *bstr* parameter is null. |