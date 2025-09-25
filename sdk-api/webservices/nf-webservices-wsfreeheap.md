# WsFreeHeap function

## Description

This frees the heap object, and the memory associated with any allocations
made on it using [WsAlloc](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsalloc).

## Parameters

### `heap` [in]

The heap to free. This must be a valid heap object that was returned
from [WsCreateHeap](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreateheap). This parameter may not be **NULL**.