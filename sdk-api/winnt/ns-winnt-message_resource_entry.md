# MESSAGE_RESOURCE_ENTRY structure

## Description

Contains the error message or message box display text for a message table resource.

## Members

### `Length`

Type: **WORD**

The length, in bytes, of the **MESSAGE_RESOURCE_ENTRY** structure.

### `Flags`

Type: **WORD**

Indicates that the string is encoded in Unicode, if equal to the value 0x0001. Indicates that the string is encoded in ANSI, if equal to the value 0x0000.

### `Text`

Type: **BYTE[1]**

Pointer to an array that contains the error message or message box display text.

## See also

**Conceptual**

[MESSAGE_RESOURCE_BLOCK](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-message_resource_block)

[MESSAGE_RESOURCE_DATA](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-message_resource_data)

**Reference**

[Resources](https://learn.microsoft.com/windows/desktop/menurc/resources)