# _MSiSCSI_NICPerformance structure

## Description

The MSiSCSI_NICPerformance structure can be used by an iSCSI initiator to report statistics for a network interface card (NIC) port.

## Members

### `BytesTransmitted`

The number of bytes that are transmitted through the Ethernet port.

### `BytesReceived`

The number of bytes that are received through the Ethernet port.

### `PDUTransmitted`

The number of PDUs that are transmitted through the Ethernet port.

### `PDUReceived`

The number of PDUs that are received through the Ethernet port.

## Remarks

It is optional that you implement this class.

## See also

[MSiSCSI_NICPerformance WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-nicperformance-wmi-class)