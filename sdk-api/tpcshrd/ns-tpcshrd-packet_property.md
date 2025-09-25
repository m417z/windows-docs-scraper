# PACKET_PROPERTY structure

## Description

Describes a packet property that is reported by the tablet driver.

## Members

### `guid`

 The property. This value is not limited to the set of predefined GUIDs. An application or a device driver may define new GUIDs at any time.

### `PropertyMetrics`

 The range, units, and resolution of the packet property.

## See also

[PACKET_DESCRIPTION Structure](https://learn.microsoft.com/windows/desktop/api/tpcshrd/ns-tpcshrd-packet_description)

[PROPERTY_METRICS Structure](https://learn.microsoft.com/windows/desktop/api/tpcshrd/ns-tpcshrd-property_metrics)