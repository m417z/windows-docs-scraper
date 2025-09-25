# MESSAGE_RESOURCE_DATA structure

## Description

Contains information about formatted text for display as an error message or in a message box in a message table resource.

## Members

### `NumberOfBlocks`

Type: **DWORD**

The number of [MESSAGE_RESOURCE_BLOCK](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-message_resource_block) structures.

### `Blocks`

Type: **[MESSAGE_RESOURCE_BLOCK](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-message_resource_block)[1]**

An array of structures. The array is the size indicated by the
**NumberOfBlocks** member.

## Remarks

A **MESSAGE_RESOURCE_DATA** structure can contain one or more
[MESSAGE_RESOURCE_BLOCK](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-message_resource_block) structures, which can each contain one or more [MESSAGE_RESOURCE_ENTRY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-message_resource_entry) structures.

## See also

**Conceptual**

[MESSAGE_RESOURCE_BLOCK](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-message_resource_block)

[MESSAGE_RESOURCE_ENTRY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-message_resource_entry)

**Reference**

[Resources](https://learn.microsoft.com/windows/desktop/menurc/resources)