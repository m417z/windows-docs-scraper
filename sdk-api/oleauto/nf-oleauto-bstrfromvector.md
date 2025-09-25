# BstrFromVector function

## Description

Returns a BSTR, assigning each element of the vector to a character in the BSTR.

## Parameters

### `psa` [in]

The vector to be converted to a BSTR.

### `pbstr` [out]

A BSTR, each character of which is assigned to an element from the vector.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_OUTOFMEMORY** | Out of memory. |
| **E_INVALIDARG** | The *psa* parameter is null. |
| **DISP_E_TYPEMISMATCH** | The argument *psa* is not a vector (not an array of bytes). |