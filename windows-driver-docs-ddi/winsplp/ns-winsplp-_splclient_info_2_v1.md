# _SPLCLIENT_INFO_2_V1 structure

## Description

Contains the handle for the server-side printer that is used to make direct API calls from the client to the server without the overhead of the RPC. The performance improvement is primarily observed in calls to read/write printer made from within the spooler (Gdi32.dll during playback). This structure is used in the private spooler RPC interface (RpcSplOpenPrinter).

## Members

### `hSplPrinter`

Specifies the server-side handle to be used for direct calls.