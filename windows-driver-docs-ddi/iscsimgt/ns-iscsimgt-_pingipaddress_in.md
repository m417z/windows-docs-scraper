# _PingIPAddress_IN structure

## Description

The PingIPAddress_IN structure holds the input data for the PingIPAddress method.

## Members

### `RequestCount`

The number of ping requests to be sent to the specified IP address.

### `RequestSize`

The size of each request (in bytes) to be sent.

### `Timeout`

The timeout (in milliseconds) for each ping request.

### `Address`

The IP address to which the ping request must be sent. The IP address is provided by the [ISCSI_IP_Address](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_ip_address) structure.

## Remarks

We recommend that you implement this class.

## See also

[ISCSI_IP_Address](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_ip_address)