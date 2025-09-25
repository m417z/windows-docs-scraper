## Description

The **WSATHREADID** structure enables a provider to identify a thread on which asynchronous procedure calls (APCs) can be queued using the [**WPUQueueApc**](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpuqueueapc) function.

## Members

```C++
} WSATHREADID, *LPWSATHREADID;
```

### `ThreadHandle`

Handle to the thread ID.

### `Reserved`

Reserved.

## Remarks

## See also

**[WPUQueueApc](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpuqueueapc)**
**[LPWSPIoctl](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspioctl)**

**[LPWSPRecv](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecv)**

**[LPWSPSend](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsend)**