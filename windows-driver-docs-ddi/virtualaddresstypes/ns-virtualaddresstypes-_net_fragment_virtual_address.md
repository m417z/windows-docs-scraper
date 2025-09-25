# NET_FRAGMENT_VIRTUAL_ADDRESS structure

## Description

The **NET_FRAGMENT_VIRTUAL_ADDRESS** structure contains payload buffer information for a [**NET_FRAGMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fragment/ns-fragment-_net_fragment).

## Members

### `VirtualAddress`

Points to the start of the packet buffer. This address is mapped into the system address space.

For transmit queues, this value is read-only.

## Remarks

To obtain this structure, call [**NetExtensionGetFragmentVirtualAddress**](https://learn.microsoft.com/windows-hardware/drivers/ddi/virtualaddress/nf-virtualaddress-netextensiongetfragmentvirtualaddress).

## See also

[Packet descriptors and extensions](https://learn.microsoft.com/windows-hardware/drivers/netcx/packet-descriptors-and-extensions)

[**NET_FRAGMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fragment/ns-fragment-_net_fragment)

[**NetExtensionGetFragmentVirtualAddress**](https://learn.microsoft.com/windows-hardware/drivers/ddi/virtualaddress/nf-virtualaddress-netextensiongetfragmentvirtualaddress)