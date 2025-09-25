# NET_FRAGMENT_MDL structure

## Description

The **NET_FRAGMENT_MDL** structure contains DMA MDL information for a [**NET_FRAGMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fragment/ns-fragment-_net_fragment).

## Members

### `Mdl`

For transmit queues, a pointer to an MDL to be used for scatter/gather DMA.

For receive queues, this member is not used.

Do not modify this value.

## Remarks

To obtain this structure, call [**NetExtensionGetFragmentMdl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mdl/nf-mdl-netextensiongetfragmentmdl).

## See also

[Packet descriptors and extensions](https://learn.microsoft.com/windows-hardware/drivers/netcx/packet-descriptors-and-extensions)

[**NET_FRAGMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fragment/ns-fragment-_net_fragment)

[**NetExtensionGetFragmentMdl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mdl/nf-mdl-netextensiongetfragmentmdl)