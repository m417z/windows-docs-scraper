# RequireNetworkDuringMediaTaskCompletion function

## Description

Increments or decrements the count of network connections required for media task completion.

## Parameters

### `requireNetwork`

If true is specified, the system's count of required network connections is incremented by one. If false is specified, the system's count of required network connections is decremented by one.

### `requireCount` [out, optional]

When provided, this parameter is populated with the current number of required network connections tracked by the system.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.