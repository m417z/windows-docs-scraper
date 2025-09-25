# SoHAttribute structure

## Description

**Note** The Network Access Protection platform is not available starting with Windows 10

The **SoHAttribute** structure defines the SoH protocol between the SHA/SHV and the NAP system.

## Members

### `type`

A [SoHAttributeType](https://learn.microsoft.com/windows/desktop/NAP/sohattributetype-enum) value that defines the attribute type contained in **value**.

### `size`

The size, in bytes, of the SoH attribute pointed to by **value** and has a range of 0 to [maxSoHAttributeSize](https://learn.microsoft.com/windows/desktop/NAP/nap-type-constants).

### `value`

A pointer to a [SoHAttributeValue](https://learn.microsoft.com/windows/desktop/NAP/sohattributevalue-union) structure that contains the SoH attribute value as defined by **type**.

## See also

[NAP Reference](https://learn.microsoft.com/windows/desktop/NAP/nap-reference)

[NAP Structures](https://learn.microsoft.com/windows/desktop/NAP/nap-structures)