# AAAccountingData structure

## Description

This structure contains information about a connection event.

## Members

### `userName`

The user name.

### `clientName`

The name of the client computer.

### `authType`

A value of the [AAAuthSchemes](https://learn.microsoft.com/windows/win32/api/tsgpolicyengine/ne-tsgpolicyengine-aaauthschemes) enumeration type that specifies the type of authentication used to connect to RD Gateway.

### `resourceName`

The name of the remote computer.

### `portNumber`

The port number of the remote computer used by the connection.

### `protocolName`

The name of the protocol used by the connection.

### `numberOfBytesReceived`

The number of bytes sent from the client to the remote computer.

### `numberOfBytesTransfered`

The number of bytes sent from the remote computer to the client.

### `reasonForDisconnect`

The reason the connection was disconnected.

### `mainSessionId`

A unique identifier assigned to the connection by RD Gateway.

### `subSessionId`

A unique identifier assigned to the subsession by RD Gateway.