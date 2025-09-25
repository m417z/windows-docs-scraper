# WdsBpAddOption function

## Description

Adds an option to the packet.

## Parameters

### `hHandle` [in]

A handle returned by the [WdsBpInitialize](https://learn.microsoft.com/windows/desktop/api/wdsbp/nf-wdsbp-wdsbpinitialize) function.

### `uOption` [in]

Specifies the option to add to the packet.

### `uValueLen` [in]

The length, in bytes, for the value.

### `pValue` [in]

A pointer to a location that contains the value for the option.

## Return value

If the function succeeds, the return is **S_OK**.