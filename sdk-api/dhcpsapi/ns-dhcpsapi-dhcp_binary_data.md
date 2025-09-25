# DHCP_BINARY_DATA structure

## Description

The **DHCP_BINARY_DATA** structure defines an opaque blob of binary data.

## Members

### `DataLength`

Specifies the size of **Data**, in bytes.

### `Data`

Pointer to an opaque blob of byte (binary) data.

The data is formatted as follows:

| Byte | Format |
| --- | --- |
| Byte 0 to byte 3 | The result of a binary AND on the IP address and the subnet mask in reverse order. |
| Byte 4 | Hardware identifier. This value is always 0x01. |
| Byte 5 to Byte 10 | The MAC address of the client. |

### `Data.size_is`

### `Data.size_is.DataLength`