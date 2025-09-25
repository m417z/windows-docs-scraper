## Description

Assigns the vector component data packed in an instance of `uint32_t` to the current
instance of `XMDEC4`.
This operator assigns the vector component data packed in an instance of `uint32_t` to
the current instance of [XMDEC4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmdec4).

**Note** This operator is only available under C++.

## Return value

The current instance of `XMDEC4` whose vector component data has been
updated to the component values packed in the `uint32_t` instance specified by
the **Packed** argument.

## Remarks

The format of **Packed** is:

* The first 10 bits (bits 0-09) of **Packed** assigned to the **x** member of the current instance of `XMDEC4`.
* The second 10 bits (bits 10-19) of **Packed** assigned to the **y** member of the current instance of `XMDEC4`.
* The third 10 bits (bits 10-29) of **Packed** assigned to the **z** member of the current instance of `XMDEC4`.
* The last 2 bits (bits 30-31) of **Packed** assigned to the **w** member of the current instance of `XMDEC4`.

## See also

**Reference**

[XMDEC4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmdec4)

[operator =](https://msdn.microsoft.com/46a34196-d32a-4ddf-9245-c568b9461f7d)