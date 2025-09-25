# TcEnumerateInterfaces function

## Description

The
**TcEnumerateInterfaces** function enumerates all traffic control–enabled network interfaces. Clients are notified of interface changes through the
[ClNotifyHandler](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nc-traffic-tci_notify_handler) function.

## Parameters

### `ClientHandle` [in]

Handle used by traffic control to identify the client. Clients receive handles when registering with traffic control through the
[TcRegisterClient](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcregisterclient) function.

### `pBufferSize` [in, out]

Pointer to a value indicating the size of the buffer. For input, this value is the size of the buffer, in bytes, allocated by the caller. For output, this value is the actual size of the buffer, in bytes, used or needed by traffic control. A value of zero on output indicates that no traffic control interfaces are available, indicating that the QOS Packet Scheduler is not installed.

### `InterfaceBuffer` [out]

Pointer to the buffer containing the returned list of interface descriptors.

## Return value

Successful completion returns the device name of the interface.

| Return code | Description |
| --- | --- |
| **NO_ERROR** | The function executed without errors. |
| **ERROR_INVALID_HANDLE** | The client handle is invalid. |
| **ERROR_INVALID_PARAMETER** | One of the parameters is **NULL**. |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer is too small to enumerate all interfaces. If this error is returned, the correct (required) size of the buffer is passed back in *pBufferSize*. |
| **ERROR_NOT_ENOUGH_MEMORY** | The system is out of memory. |

## Remarks

The client calling the
**TcEnumerateInterfaces** function must first allocate a buffer, then pass the buffer to traffic control through *InterfaceBuffer*. Traffic control returns a pointer to an array of interface descriptors in *InterfaceBuffer*. Each interface descriptor contains two elements:

* The traffic control interface's identifying text string.
* The network address list descriptor currently associated with the interface.

The network address list descriptor includes the media type, as well as a list of network addresses. The media type determines how the network address list should be interpreted:

* For connectionless media such as a LAN, the network address list contains all the protocol-specific addresses associated with the interface.
* For connection-oriented media such as a WAN, the network address list contains an even number of network addresses:

  + The first address in each pair represents the local (source) address of the interface.
  + The second address in each pair represents the remote (destination) address of the interface.

**Note** Use of the
**TcEnumerateInterfaces** function requires administrative privilege.

## See also

[ClNotifyHandler](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nc-traffic-tci_notify_handler)

[TcRegisterClient](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcregisterclient)