# NUMPARSE structure

## Description

Specifies numeric parsing information.

## Members

### `cDig`

On input, the size of the array. On output, the number of items written to the rgbDig array.

### `dwInFlags`

Input flags.

#### NUMPRS_CURRENCY (0x0400)

#### NUMPRS_DECIMAL (0x0100)

#### NUMPRS_EXPONENT (0x0800)

#### NUMPRS_HEX_OCT (0x0040)

#### NUMPRS_LEADING_MINUS (0x0100)

#### NUMPRS_LEADING_PLUS (0x0004)

#### NUMPRS_LEADING_WHITE (0x0001)

#### NUMPRS_PARENS (0x0080)

#### NUMPRS_STD (0x1FFF)

#### NUMPRS_THOUSANDS (0x0200)

#### NUMPRS_TRAILING_MINUS (0x0020)

#### NUMPRS_TRAILING_PLUS (0x0008)

#### NUMPRS_TRAILING_WHITE (0x0002)

#### NUMPRS_USE_ALL (0x1000)

### `dwOutFlags`

Output flags. Includes all the values for **dwInFlags**, plus the following values.

#### NUMPRS_INEXACT (0x20000)

#### NUMPRS_NEG (0x10000)

### `cchUsed`

Receives the number of characters (from the beginning of the string) that were successfully parsed.

### `nBaseShift`

The number of bits per digit (3 or 4 for octal and hexadecimal numbers, and zero for decimal).

### `nPwr10`

The decimal point position.

## Remarks

The following apply only to decimal numbers:

* **nPwr10** sets the decimal point position by giving the power of 10 of the least significant digit.
* If the number is negative, **NUMPRS_NEG** will be set in **dwOutFlags**.
* If there are more non-zero decimal digits than will fit into the digit array, the NUMPRS_INEXACT flag will be set.