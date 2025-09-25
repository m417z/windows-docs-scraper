# _NET_EXTENSION structure

## Description

The **NET_EXTENSION** structure represents a packet extension for all packets in a packet queue.

## Members

### `Reserved`

Reserved. Client drivers must not read or write to this value.

### `DUMMYUNIONNAME`

A union that contains the **Enabled** and **Reserved1** members.

### `DUMMYUNIONNAME.Enabled`

A boolean value that indicates if this extension is currently enabled for the packets in this queue.

### `DUMMYUNIONNAME.Reserved1`

Reserved. Client drivers must not read or write to this value.

## Remarks

Client drivers typically store packet extensions in the context space for each queue during queue creation, reducing calls out of the driver. Later, to retrieve packet extension information for a particular packet, the driver calls one of the wrapper functions around [**NetExtensionGetData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/extension/nf-extension-netextensiongetdata).

- For checksum offload information, the client driver calls [**NetExtensionGetPacketChecksum**](https://learn.microsoft.com/windows-hardware/drivers/ddi/checksum/nf-checksum-netextensiongetpacketchecksum).

For examples of creating packet queues, see [Transmit and receive queues](https://learn.microsoft.com/windows-hardware/drivers/netcx/transmit-and-receive-queues).

## See also

[Transmit and receive queues](https://learn.microsoft.com/windows-hardware/drivers/netcx/transmit-and-receive-queues)

[**NetExtensionGetPacketChecksum**](https://learn.microsoft.com/windows-hardware/drivers/ddi/checksum/nf-checksum-netextensiongetpacketchecksum)