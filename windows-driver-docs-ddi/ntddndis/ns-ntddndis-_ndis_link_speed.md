# _NDIS_LINK_SPEED structure

## Description

The NDIS_LINK_SPEED structure specifies transmit and receive link speeds.

## Members

### `XmitLinkSpeed`

The transmit link speed in bits per second. A value of -1 in this member indicates that the
transmit link speed is unknown.

### `RcvLinkSpeed`

The receive link speed in bits per second. A value of -1 in this member indicates that the receive
link speed is unknown.

## Remarks

The NDIS_LINK_SPEED structure specifies link speeds in the
[OID_GEN_LINK_SPEED_EX](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-link-speed-ex) and
[OID_GEN_MAX_LINK_SPEED](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-max-link-speed) OIDs.

## See also

[OID_GEN_LINK_SPEED_EX](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-link-speed-ex)

[OID_GEN_MAX_LINK_SPEED](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-max-link-speed)