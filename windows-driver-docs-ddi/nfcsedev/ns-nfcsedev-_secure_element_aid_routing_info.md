# _SECURE_ELEMENT_AID_ROUTING_INFO structure

## Description

SECURE_ELEMENT_AID_ROUTING_INFO is a member of [SECURE_ELEMENT_ROUTING_TABLE_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfcsedev/ns-nfcsedev-_secure_element_routing_table_entry).

## Members

### `guidSecureElementId`

Secure element unique identifier returned by enumeration DDI.

### `cbAid`

Length of applet ID buffer.

### `pbAid[ISO_7816_MAXIMUM_AID_LENGTH]`

Buffer holding ISO 7816 AID.

## see-also

- [SECURE_ELEMENT_ROUTING_TABLE_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfcsedev/ns-nfcsedev-_secure_element_routing_table_entry)