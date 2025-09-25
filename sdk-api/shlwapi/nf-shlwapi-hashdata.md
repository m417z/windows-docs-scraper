# HashData function

## Description

Hashes an array of data.

## Parameters

### `pbData` [in]

Type: **BYTE***

A pointer to the data array.

### `cbData`

Type: **DWORD**

The number of elements in the array at *pbData*.

### `pbHash` [out]

Type: **BYTE***

A pointer to a value that, when this function returns successfully, receives the hashed array.

### `cbHash`

Type: **DWORD**

The number of elements in *pbHash*. It should be no larger than 256.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.