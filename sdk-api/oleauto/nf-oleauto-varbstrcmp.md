# VarBstrCmp function

## Description

Compares two variants of type BSTR.

## Parameters

### `bstrLeft` [in]

The first variant.

### `bstrRight` [in]

The second variant.

### `lcid` [in]

The locale identifier of the program to determine whether UNICODE or ANSI strings are being used.

### `dwFlags` [in]

The following are compare results flags.

| Value | Meaning |
| --- | --- |
| **NORM_IGNORECASE**<br><br>0x00000001 | Ignore case. |
| **NORM_IGNORENONSPACE**<br><br>0x00000002 | Ignore nonspace characters. |
| **NORM_IGNORESYMBOLS**<br><br>0x00000004 | Ignore symbols. |
| **NORM_IGNOREWIDTH**<br><br>0x00000008 | Ignore string width. |
| **NORM_IGNOREKANATYPE**<br><br>0x00000040 | Ignore Kana type. |
| **NORM_IGNOREKASHIDA**<br><br>0x00040000 | Ignore Arabic kashida characters. |

## Return value

This function can return one of these values.

| Return code/value | Description |
| --- | --- |
| **VARCMP_LT**<br><br>0 | *bstrLeft* is less than *bstrRight*. |
| **VARCMP_EQ**<br><br>1 | The parameters are equal. |
| **VARCMP_GT**<br><br>2 | *bstrLeft* is greater than *bstrRight*. |

## Remarks

This function will not compare arrays or records.