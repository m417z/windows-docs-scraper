# DwmGetTransportAttributes function

## Description

Retrieves transport attributes.

## Parameters

### `pfIsRemoting` [out]

A pointer to a **BOOL** value that indicates whether the transport supports remoting. **TRUE** if the transport supports remoting; otherwise, **FALSE**.

### `pfIsConnected` [out]

A pointer to a **BOOL** value that indicates whether the transport is connected. **TRUE** if the transport is connected; otherwise, **FALSE**.

### `pDwGeneration` [out]

A pointer to a **DWORD** that receives a generation value for the transport.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.