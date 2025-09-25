# WdsBpQueryOption function

## Description

Returns the value of an option from the parsed packet.

## Parameters

### `hHandle` [in]

A handle returned by the [WdsBpParseInitialize](https://learn.microsoft.com/windows/desktop/api/wdsbp/nf-wdsbp-wdsbpparseinitialize) function.

### `uOption` [in]

Specifies the option to add to the packet.

### `uValueLen` [out]

The total number of bytes of memory pointed to by the *pValue* parameter. To determine the number of bytes required to store the value for the option, set *uValueLen* to zero and *pValue* to **NULL**; the **WdsBpQueryOption** function returns **ERROR_INSUFFICIENT_BUFFER**, and the location pointed to by the *puBytes* parameter receives the number of bytes required for the value.

### `pValue` [out]

The value of the option is returned in this buffer.

### `puBytes` [out]

If the buffer is large enough for the value, this parameter receives the number of bytes copied to *pValue*. If not enough space is available, this parameter receives the total number of bytes required to store the value.

## Return value

If the function succeeds, the return is **S_OK**.