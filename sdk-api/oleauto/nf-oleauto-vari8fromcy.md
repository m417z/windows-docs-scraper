## Description

> [!IMPORTANT]
> This API is affected by the problem described in Microsoft Support topic [VarI8FromCy produces incorrect value when CY value is very large](https://support.microsoft.com/help/2282810).

Converts a currency value to an 8-byte integer value.

## Parameters

### `cyIn` [in]

The value to convert.

### `pi64Out` [out]

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