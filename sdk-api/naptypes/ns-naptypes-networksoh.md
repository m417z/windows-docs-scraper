# NetworkSoH structure

## Description

**Note** The Network Access Protection platform is not available starting with Windows 10

The **NetworkSoH** structure defines the wire SoH protocol.

## Members

### `size`

The size, in bytes, of the data blob in the range [minNetworkSoHSize](https://learn.microsoft.com/windows/desktop/NAP/nap-type-constants) to **maxNetworkSoHSize**.

### `data`

A pointer to a data blob that contains the [SoH](https://learn.microsoft.com/windows/desktop/api/naptypes/ns-naptypes-soh) structure in network byte order.

## See also

[NAP Reference](https://learn.microsoft.com/windows/desktop/NAP/nap-reference)

[NAP Structures](https://learn.microsoft.com/windows/desktop/NAP/nap-structures)