# WSAPROTOCOLCHAIN structure

## Description

The
**WSAPROTOCOLCHAIN** structure contains a counted list of Catalog Entry identifiers that comprise a protocol chain.

## Members

### `ChainLen`

Length of the chain, in bytes. The following settings apply:

Setting **ChainLen** to zero indicates a layered protocol

Setting **ChainLen** to one indicates a base protocol

Setting **ChainLen** to greater than one indicates a protocol chain

### `ChainEntries`

Array of protocol chain entries.

## Remarks

If the length of the chain is larger than 1, this structure represents a protocol chain which consists of one or more layered protocols on top of a base protocol. The corresponding Catalog Entry IDs are in the ProtocolChain.ChainEntries array starting with the layered protocol at the top (the zeroth element in the ProtocolChain.ChainEntries array) and ending with the base protocol. Refer to Windows Sockets 2 Service Provider Interface for more information on protocol chains.

## See also

[WSAEnumProtocols](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumprotocolsa)