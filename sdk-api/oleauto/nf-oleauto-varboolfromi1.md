# VarBoolFromI1 function

## Description

Converts a char value to a Boolean value.

## Parameters

### `cIn` [in]

The value to convert.

### `pboolOut` [out]

The resulting value.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **DISP_E_BADVARTYPE** | The input parameter is not a valid type of variant. |
| **DISP_E_OVERFLOW** | The data pointed to by the output parameter does not fit in the destination type. |
| **DISP_E_TYPEMISMATCH** | The argument could not be coerced to the specified type. |
| **E_INVALIDARG** | One of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |