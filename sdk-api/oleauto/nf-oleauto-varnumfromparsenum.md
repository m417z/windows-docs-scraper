# VarNumFromParseNum function

## Description

Converts parsed results to a variant.

## Parameters

### `pnumprs` [in]

The parsed results. The **cDig** member of this argument specifies the number of digits present in *rgbDig*.

### `rgbDig` [in]

The values of the digits. The **cDig** field of *pnumprs* contains the number of digits.

### `dwVtBits` [in]

One bit set for each type that is acceptable as a return value (in many cases, just one bit).

#### VTBIT_I1

#### VTBIT_UI1

#### VTBIT_I2

#### VTBIT_UI2

#### VTBIT_I4

#### VTBIT_UI4

#### VTBIT_R4

#### VTBIT_R8

#### VTBIT_CY

#### VTBIT_DECIMAL

### `pvar` [out]

The variant result.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_OUTOFMEMORY** | Out of memory. |
| **DISP_E_OVERFLOW** | The number is too large to be represented in an allowed type. There is no error if precision is lost in the conversion. |

## Remarks

For rounding decimal numbers, the digit array must be at least one digit longer than the maximum required for data types. The maximum number of digits required for the DECIMAL data type is 29, so the digit array must have room for 30 digits. There must also be enough digits to accept the number in octal, if that parsing options is selected. (Hexadecimal and octal numbers are limited by **VarNumFromParseNum** to the magnitude of an unsigned long [32 bits], so they need 11 octal digits.)