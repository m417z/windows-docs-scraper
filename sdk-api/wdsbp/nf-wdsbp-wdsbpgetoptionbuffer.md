# WdsBpGetOptionBuffer function

## Description

Copies information into a buffer that should be added to your DHCP packet options.

## Parameters

### `hHandle` [in]

A handle to the packet. This handle must have been returned by the [WdsBpInitialize](https://learn.microsoft.com/windows/desktop/api/wdsbp/nf-wdsbp-wdsbpinitialize) function.

### `uBufferLen` [in]

The total number of bytes of memory pointed to by the *pBuffer* parameter. To determine the amount of memory required, call the **WdsBpGetOptionBuffer** function with *uBufferLen* set to zero and *pBuffer* set to **NULL**. The location pointed to by the *puBytes* parameter then receives the size required.

### `pBuffer` [out]

A pointer to a location in memory that receives the information that is being sent to the network boot program.

### `puBytes` [out]

The number of bytes copied to the buffer.

## Return value

If the function succeeds, the return is **S_OK**.