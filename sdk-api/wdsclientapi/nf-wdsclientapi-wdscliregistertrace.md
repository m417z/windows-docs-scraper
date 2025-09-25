# WdsCliRegisterTrace function

## Description

Registers a callback function that will receive debugging messages.

## Parameters

### `pfn` [in, optional]

A pointer to a [PFN_WdsCliTraceFunction](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nc-wdsclientapi-pfn_wdsclitracefunction) callback function that receives debugging messages.

## Return value

If the function succeeds, the return is **S_OK**.