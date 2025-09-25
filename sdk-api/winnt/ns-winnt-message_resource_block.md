# MESSAGE_RESOURCE_BLOCK structure

## Description

Contains information about message strings with identifiers in the range indicated by the
**LowId** and
**HighId** members.

## Members

### `LowId`

Type: **DWORD**

The lowest message identifier contained within this structure.

### `HighId`

Type: **DWORD**

The highest message identifier contained within this structure.

### `OffsetToEntries`

Type: **DWORD**

The offset, in bytes, from the beginning of the [MESSAGE_RESOURCE_DATA](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-message_resource_data) structure to the [MESSAGE_RESOURCE_ENTRY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-message_resource_entry) structures in this **MESSAGE_RESOURCE_BLOCK**. The **MESSAGE_RESOURCE_ENTRY** structures contain the message strings.

## See also

**Conceptual**

[MESSAGE_RESOURCE_DATA](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-message_resource_data)

[MESSAGE_RESOURCE_ENTRY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-message_resource_entry)

**Reference**

[Resources](https://learn.microsoft.com/windows/desktop/menurc/resources)