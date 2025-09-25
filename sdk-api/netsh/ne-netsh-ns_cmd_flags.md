# NS_CMD_FLAGS enumeration

## Description

The **NS_CMD_FLAGS** enumeration specifies command flags available in NetShell.

## Constants

### `CMD_FLAG_PRIVATE:0x01`

Indicates a private command. This command is not valid in subcontexts.

### `CMD_FLAG_INTERACTIVE:0x02`

Indicates an interactive command. This command is not valid from outside NetShell.

### `CMD_FLAG_LOCAL:0x08`

Indicates a local command. This command is not valid from remote computers.

### `CMD_FLAG_ONLINE:0x10`

Indicates a command is valid only when online. This command is not valid in offline or noncommit mode.

### `CMD_FLAG_HIDDEN:0x20`

Indicates a command is not in online Help, but can be executed.

### `CMD_FLAG_LIMIT_MASK:0xffff`

Indicates that the command limits the mask.

### `CMD_FLAG_PRIORITY`

Indicates that the **ulPriority** field is used.