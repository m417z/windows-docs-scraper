# DHCP_ATTRIB structure

## Description

The **DHCP_ATTRIB** structure defines an attribute set on the DHCP server.

## Members

### `DhcpAttribId`

[DHCP_ATTRIB_ID](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) structure that uniquely identifies the DHCP server attribute.

### `DhcpAttribType`

Specifies exactly one of the following attribute types.

| Value | Meaning |
| --- | --- |
| **DHCP_ATTRIB_BOOL_IS_ROGUE**<br><br>0x01 | The DHCP server is rogue. |
| **DHCP_ATTRIB_BOOL_IS_DYNBOOTP**<br><br>0x02 | The DHCP server supports BOOTP for dynamic address service. |
| **DHCP_ATTRIB_BOOL_IS_PART_OF_DSDC**<br><br>0x03 | The DHCP server is part of the directory service domain controller. |
| **DHCP_ATTRIB_BOOL_IS_BINDING_AWARE**<br><br>0x04 | The DHCP server is binding aware. |
| **DHCP_ATTRIB_BOOL_IS_ADMIN**<br><br>0x05 | The DHCP server is the admin-level DHCP server. |
| **DHCP_ATTRIB_ULONG_RESTORE_STATUS**<br><br>0x06 | The DHCP server can restore status with the provided attribute value. |

### `DhcpAttribBool.case`

### `DhcpAttribBool.case.DHCP_ATTRIB_TYPE_BOOL`

### `DhcpAttribUlong.case`

### `DhcpAttribUlong.case.DHCP_ATTRIB_TYPE_ULONG`

### `DhcpAttribBool`

### `DhcpAttribUlong`

## Remarks

A DHCP server attribute is a value that can be queried to determine supported and available features.