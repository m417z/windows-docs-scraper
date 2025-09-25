# DISPLAYCONFIG_TOPOLOGY_ID enumeration

## Description

The DISPLAYCONFIG_TOPOLOGY_ID enumeration specifies the type of display topology.

## Constants

### `DISPLAYCONFIG_TOPOLOGY_INTERNAL:0x00000001`

Indicates that the display topology is an internal configuration.

### `DISPLAYCONFIG_TOPOLOGY_CLONE:0x00000002`

Indicates that the display topology is clone-view configuration.

### `DISPLAYCONFIG_TOPOLOGY_EXTEND:0x00000004`

Indicates that the display topology is an extended configuration.

### `DISPLAYCONFIG_TOPOLOGY_EXTERNAL:0x00000008`

Indicates that the display topology is an external configuration.

### `DISPLAYCONFIG_TOPOLOGY_FORCE_UINT32:0xFFFFFFFF`

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. You should not use this value.