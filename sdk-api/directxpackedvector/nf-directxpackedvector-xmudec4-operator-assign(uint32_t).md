# XMUDEC4::operator = (const uint32_t)

## Description

Assigns the vector component data packed in an instance of **uint32_t** to the current instance of [XMUDEC4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmudec4).

This operator assigns the vector component data packed in an instance of **uint32_t** to the current instance of **XMUDEC4**.

**Note** This operator is only available under C++.

## Parameters

### `Packed`

The values of four vector components in a packed format.

## Return value

The current instance of **XMUDEC4** whose vector component data has been updated to the component values packed in the **uint32_t** instance specified by the *Packed* argument.

## Remarks

The format of Packed is:

* The first 10 bits (bits 0-09) of *Packed* assigned to the **x** member of the current instance of **XMUDEC4**.
* The second 10 bits (bits 10-19) of *Packed* assigned to the **y** member of the current instance of **XMUDEC4**.
* The third 10 bits (bits 10-29) of *Packed* assigned to the **z** member of the current instance of **XMUDEC4**.
* The last 2 bits (bits 30-31) of *Packed* assigned to the **w** member of the current instance of **XMUDEC4**.

## See also

[XMUDEC4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmudec4)