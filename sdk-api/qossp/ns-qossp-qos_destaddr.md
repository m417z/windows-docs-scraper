# QOS_DESTADDR structure

## Description

The QOS object
**QOS_DESTADDR** is used during a call to the
[WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl) (SIO_SET_QOS) function in order to avoid issuing a **connect** function call for a sending socket.

## Members

### `ObjectHdr`

The QOS object
[QOS_OBJECT_HDR](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos/ns-qos-qos_object_hdr). The object type for this QOS object should be
**QOS_DESTADDR**.

### `SocketAddress`

Address of the destination socket.

### `sockaddr`

### `SocketAddressLength`

Length of the **SocketAddress** structure.

## See also

[QOS_OBJECT_HDR](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos/ns-qos-qos_object_hdr)

[WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl)