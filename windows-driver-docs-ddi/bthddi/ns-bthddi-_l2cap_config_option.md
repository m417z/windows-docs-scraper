# _L2CAP_CONFIG_OPTION structure

## Description

An array of L2CAP_CONFIG_OPTION structures is used to specify values for the
**ExtraOptions** member of the
[CHANNEL_CONFIG_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_channel_config_parameters),
[_BRB_L2CA_OPEN_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_open_channel), and
[INDICATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_indication_parameters) structures.

## Members

### `Header`

A
[CO_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_co_header) structure that specifies information
about vendor-specific configuration options.

### `DynamicBuffer`

A pointer to a buffer that contains additional L2CAP channel parameters that are defined either by
the profile driver or the remote device. The
**Flags** member is set to CO_DYNAMIC to indicate that this member contains the extra
parameters.

### `FixedBuffer`

A buffer that contains additional L2CAP channel parameters that are defined either by the profile
driver or the remote device if they fit into 4 bytes. The
**Flags** member is set to CO_FIXED to indicate that this member contains the extra parameters.

### `Flags`

A combination of flags that determines which of this structure's buffer members contain
parameters. Multiple flags can be set at once. Valid flag values are listed in the following table.

| Flag | Description |
| --- | --- |
| CO_DYNAMIC | If set, the **DynamicBuffer** member points to the extra parameters. |
| CO_FIXED | If set, the **FixedBuffer** member contains the extra parameters. |

## See also

[CHANNEL_CONFIG_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_channel_config_parameters)

[INDICATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_indication_parameters)

[_BRB_L2CA_OPEN_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_open_channel)