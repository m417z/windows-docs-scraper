# SOCKET_PROCESSOR_AFFINITY structure

## Description

The **SOCKET_PROCESSOR_AFFINITY** structure contains the association between a socket and an RSS processor core and NUMA node..

## Members

### `Processor`

A structure to represent a system wide processor number. This [PROCESSOR_NUMBER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-processor_number) structure contains a
group number and relative processor number within the group.

### `NumaNodeId`

The NUMA node ID.

### `Reserved`

A value reserved for future use.

## Remarks

The **SOCKET_PROCESSOR_AFFINITY** structure is supported on Windows 8, and Windows Server 2012, and later versions of the operating system.

The [SIO_QUERY_RSS_PROCESSOR_INFO](https://learn.microsoft.com/windows/win32/winsock/sio-query-rss-processor-info)
IOCTL is used to determine the association between a socket and an RSS processor core and NUMA node. This IOCTL returns a **SOCKET_PROCESSOR_AFFINITY** structure that contains the processor number and the NUMA node ID.

## See also

[PROCESSOR_NUMBER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-processor_number)

[SIO_QUERY_RSS_PROCESSOR_INFO](https://learn.microsoft.com/windows/win32/winsock/sio-query-rss-processor-info)