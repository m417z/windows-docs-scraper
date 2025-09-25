# IBrowserService::GetNavigateState

## Description

Deprecated. Retrieves the browser's current navigation state.

## Parameters

### `pbnstate` [out]

Type: **[BNSTATE](https://learn.microsoft.com/windows/desktop/api/shdeprecated/ne-shdeprecated-bnstate)***

A pointer to a value from the [BNSTATE](https://learn.microsoft.com/windows/desktop/api/shdeprecated/ne-shdeprecated-bnstate) enumeration indicating the current navigation state.

#### BNS_NORMAL (0)

The normal state.

#### BNS_BEGIN_NAVIGATE (1)

A begin navigation event has occurred.

#### BNS_NAVIGATE (2)

A navigation event has occurred.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.