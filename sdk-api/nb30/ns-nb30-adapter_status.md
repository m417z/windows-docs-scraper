# ADAPTER_STATUS structure

## Description

[[Netbios](https://learn.microsoft.com/previous-versions/windows/desktop/netbios/portal) is not supported on Windows Vista, Windows Server 2008, and subsequent versions of the operating system]

The **ADAPTER_STATUS** structure contains information about a network adapter. This structure is pointed to by the **ncb_buffer** member of the [NCB](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-ncb) structure. **ADAPTER_STATUS** is followed by as many [NAME_BUFFER](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-name_buffer) structures as required to describe the network adapters on the system.

## Members

### `adapter_address`

Specifies encoded address of the adapter.

### `rev_major`

Specifies the major software-release level. This value is 3 for IBM NetBIOS 3. x.

### `reserved0`

Reserved. This value is always zero.

### `adapter_type`

Specifies the adapter type. This value is 0xFF for a Token Ring adapter or 0xFE for an Ethernet adapter.

### `rev_minor`

Specifies the minor software-release level. This value is zero for IBM NetBIOS x.0.

### `duration`

Specifies the duration of the reporting period, in minutes.

### `frmr_recv`

Specifies the number of FRMR frames received.

### `frmr_xmit`

Specifies the number of FRMR frames transmitted.

### `iframe_recv_err`

Specifies the number of I frames received in error.

### `xmit_aborts`

Specifies the number of aborted transmissions.

### `xmit_success`

Specifies the number of successfully transmitted packets.

### `recv_success`

Specifies the number of successfully received packets.

### `iframe_xmit_err`

Specifies the number of I frames transmitted in error.

### `recv_buff_unavail`

Specifies the number of times a buffer was not available to service a request from a remote computer.

### `t1_timeouts`

Specifies the number of times that the DLC T1 timer timed out.

**Windows 95:** DLC is no longer supported.

### `ti_timeouts`

Specifies the number of times that the ti inactivity timer timed out. The ti timer is used to detect links that have been broken.

### `reserved1`

Reserved. This value is always zero.

### `free_ncbs`

Specifies the current number of free network control blocks.

### `max_cfg_ncbs`

Undefined for IBM NetBIOS 3.0.

### `max_ncbs`

Undefined for IBM NetBIOS 3.0.

### `xmit_buf_unavail`

Undefined for IBM NetBIOS 3.0.

### `max_dgram_size`

Specifies the maximum size of a datagram packet. This value is always at least 512 bytes.

### `pending_sess`

Specifies the number of pending sessions.

### `max_cfg_sess`

Specifies the configured maximum pending sessions.

### `max_sess`

Undefined for IBM NetBIOS 3.0.

### `max_sess_pkt_size`

Specifies the maximum size of a session data packet.

### `name_count`

Specifies the number of names in the local names table.

## See also

[NAME_BUFFER](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-name_buffer)

[NCB](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-ncb)

[NetBIOS Structures](https://learn.microsoft.com/previous-versions/windows/desktop/netbios/netbios-structures)

[The NetBIOS Interface Overview](https://learn.microsoft.com/previous-versions/windows/desktop/netbios/portal)