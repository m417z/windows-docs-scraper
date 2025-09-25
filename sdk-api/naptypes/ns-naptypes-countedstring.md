# CountedString structure

## Description

**Note** The Network Access Protection platform is not available starting with Windows 10

The **CountedString** structure defines a null-terminated string with a defined length.

## Members

### `length`

The size, in characters, of the string within the range 0 to [maxStringLength](https://learn.microsoft.com/windows/desktop/NAP/nap-type-constants).

**Note** **length** does not include the null terminator.

### `string`

A pointer to a null-terminated wide character string of size **length** + 1.

## See also

[NAP Reference](https://learn.microsoft.com/windows/desktop/NAP/nap-reference)

[NAP Structures](https://learn.microsoft.com/windows/desktop/NAP/nap-structures)