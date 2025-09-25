# _CHANNEL_CONFIG_PARAMETERS structure

## Description

The CHANNEL_CONFIG_PARAMETERS structure contains configuration parameters for inbound and outbound
directions of a L2CAP channel.

## Members

### `Flags`

A flag or combination of flags that specifies which members of this structure contain data. Valid
flag values are listed in the following table.

| Flag | Description |
| --- | --- |
| CFG_EXTRA | If set, the **ExtraOptions** member contains data. |
| CFG_FLUSHTO | If set, the **FlushTO** member contains data. |
| CFG_MTU | If set, the **Mtu** member contains data. |
| CFG_QOS | If set, the **Flow** member contains data. |

### `Mtu`

The message transfer units for the specified channel direction.

### `FlushTO`

The flush timeout for the specified channel direction.

### `NumExtraOptions`

The number of items specified in the array that is specified in the
**ExtraOptions** member.

### `ExtraOptions`

The number of items specified in the array that is specified in the
**ExtraOptions** member.

### `Flow`

The QoS settings for the specified channel direction.

## See also

[L2CAP_CONFIG_OPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_l2cap_config_option)