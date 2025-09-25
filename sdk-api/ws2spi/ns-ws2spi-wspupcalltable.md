# WSPUPCALLTABLE structure

## Description

The
**WSPUPCALLTABLE** structure contains a table of pointers to service provider upcall functions.

## Members

### `lpWPUCloseEvent`

Type: **LPWPUCLOSEEVENT**

A pointer to the [WPUCloseEvent](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpucloseevent) function.

### `lpWPUCloseSocketHandle`

Type: **LPWPUCLOSESOCKETHANDLE**

A pointer to the [WPUCloseSocketHandle](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpuclosesockethandle) function.

### `lpWPUCreateEvent`

Type: **LPWPUCREATEEVENT**

A pointer to the [WPUCreateEvent](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpucreateevent) function.

### `lpWPUCreateSocketHandle`

Type: **LPWPUCREATESOCKETHANDLE**

A pointer to the [WPUCreateSocketHandle](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpucreatesockethandle) function.

### `lpWPUFDIsSet`

Type: **LPWPUFDISSET**

A pointer to the [WPUFDIsSet](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpufdisset) function.

### `lpWPUGetProviderPath`

Type: **LPWPUGETPROVIDERPATH**

A pointer to the [WPUGetProviderPath](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpugetproviderpath) function.

### `lpWPUModifyIFSHandle`

Type: **LPWPUMODIFYIFSHANDLE**

A pointer to the [WPUModifyIFSHandle](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpumodifyifshandle) function.

### `lpWPUPostMessage`

Type: **LPWPUPOSTMESSAGE**

A pointer to the [WPUPostMessage](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpupostmessage) function.

### `lpWPUQueryBlockingCallback`

Type: **LPWPUQUERYBLOCKINGCALLBACK**

A pointer to the [WPUQueryBlockingCallback](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpuqueryblockingcallback) function.

### `lpWPUQuerySocketHandleContext`

Type: **LPWPUQUERYSOCKETHANDLECONTEXT**

A pointer to the [WPUQuerySocketHandleContext](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpuquerysockethandlecontext) function.

### `lpWPUQueueApc`

Type: **LPWPUQUEUEAPC**

A pointer to the [WPUQueueApc](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpuqueueapc) function.

### `lpWPUResetEvent`

Type: **LPWPURESETEVENT**

A pointer to the [WPUResetEvent](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpuresetevent) function.

### `lpWPUSetEvent`

Type: **LPWPUSETEVENT**

A pointer to the [WPUSetEvent](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpusetevent) function.

### `lpWPUOpenCurrentThread`

Type: **LPWPUOPENCURRENTTHREAD**

A pointer to the [WPUOpenCurrentThread](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpuopencurrentthread) function.

### `lpWPUCloseThread`

Type: **LPWPUCLOSETHREAD**

A pointer to the [WPUCloseThread](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpuclosethread) function.

## Remarks

The **WSPUPCALLTABLE** structure contains a table of pointers to service provider upcall functions that are passed to the [WSPStartup](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wspstartup) function.

## See also

[WPUCloseEvent](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpucloseevent)

[WPUCloseSocketHandle](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpuclosesockethandle)

[WPUCloseThread](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpuclosethread)

[WPUCreateEvent](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpucreateevent)

[WPUCreateSocketHandle](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpucreatesockethandle)

[WPUFDIsSet](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpufdisset)

[WPUGetProviderPath](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpugetproviderpath)

[WPUModifyIFSHandle](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpumodifyifshandle)

[WPUOpenCurrentThread](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpuopencurrentthread)

[WPUPostMessage](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpupostmessage)

[WPUQueryBlockingCallback](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpuqueryblockingcallback)

[WPUQuerySocketHandleContext](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpuquerysockethandlecontext)

[WPUQueueApc](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpuqueueapc)

[WPUResetEvent](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpuresetevent)

[WPUSetEvent](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpusetevent)

[WSPStartup](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wspstartup)