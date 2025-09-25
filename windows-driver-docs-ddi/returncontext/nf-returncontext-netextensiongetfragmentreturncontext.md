# NetExtensionGetFragmentReturnContext function

## Description

The **NetExtensionGetFragmentReturnContext** function retrieves the return context extension information for a net fragment.

## Parameters

### `Extension`

A pointer to a [**NET_EXTENSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/extension/ns-extension-_net_extension) structure that describes the return context extension information for this fragment.

### `Index`

The index in the fragment ring for the target [**NET_FRAGMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fragment/ns-fragment-_net_fragment).

## Return value

Returns a pointer to a [**NET_FRAGMENT_RETURN_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/returncontexttypes/ns-returncontexttypes-_net_fragment_return_context) structure that contains the return context information for the fragment.

## Remarks

NIC client drivers typically query offsets for fragment extensions during datapath queue creation, then store them in their queue context space so they don't have to query them too often. For an example of this, see [Transmit and receive queues](https://learn.microsoft.com/windows-hardware/drivers/netcx/transmit-and-receive-queues). Clients can retrieve the return context offset from the queue context to pass to **NetExtensionGetFragmentReturnContext**.

This function is a wrapper function around [**NetExtensionGetData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/extension/nf-extension-netextensiongetdata).

## See also

[Transmit and receive queues](https://learn.microsoft.com/windows-hardware/drivers/netcx/transmit-and-receive-queues)

[Packet descriptors and extensions](https://learn.microsoft.com/windows-hardware/drivers/netcx/packet-descriptors-and-extensions)

[**NetExtensionGetData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/extension/nf-extension-netextensiongetdata)