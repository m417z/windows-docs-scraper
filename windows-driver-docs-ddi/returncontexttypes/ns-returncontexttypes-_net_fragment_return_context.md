# NET_FRAGMENT_RETURN_CONTEXT structure

## Description

The **NET_FRAGMENT_RETURN_CONTEXT** structure contains return context information for a [**NET_FRAGMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fragment/ns-fragment-_net_fragment).

## Members

### `Handle`

A handle to a driver-allocated context space structure.

For more information about receive path capabilities, see [**NET_ADAPTER_RX_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_rx_capabilities).

## Remarks

To obtain this structure, call [**NetExtensionGetFragmentReturnContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/returncontext/nf-returncontext-netextensiongetfragmentreturncontext).

## See also

[Packet descriptors and extensions](https://learn.microsoft.com/windows-hardware/drivers/netcx/packet-descriptors-and-extensions)

[**NET_FRAGMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fragment/ns-fragment-_net_fragment)

[**NetExtensionGetFragmentReturnContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/returncontext/nf-returncontext-netextensiongetfragmentreturncontext)