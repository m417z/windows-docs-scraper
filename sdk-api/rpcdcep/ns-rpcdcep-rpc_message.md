# RPC_MESSAGE structure

## Description

The **RPC_MESSAGE** structure contains information shared between NDR and the rest of the RPC or OLE runtime.

## Members

### `Handle`

Reserved.

### `DataRepresentation`

Data representation of the network buffer as defined by the NDR specification.

### `Buffer`

Pointer to the beginning of the network buffer.

### `BufferLength`

Size, in bytes, of **Buffer**.

### `ProcNum`

Reserved.

### `TransferSyntax`

Reserved.

### `RpcInterfaceInformation`

Reserved.

### `ReservedForRuntime`

Reserved.

### `ManagerEpv`

Reserved.

### `ImportContext`

Reserved.

### `RpcFlags`

Reserved.