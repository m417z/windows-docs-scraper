# _NDIS_PM_PACKET_PATTERN structure

## Description

The NDIS_PM_PACKET_PATTERN structure specifies a wake-up pattern, which, when detected by a network adapter that
has pattern-match enabled, causes the network adapter to signal a power-management wake-up event.

## Members

### `Priority`

This member is reserved.

### `Reserved`

This member is reserved.

### `MaskSize`

Specifies the size in bytes of the pattern mask that immediately follows the
NDIS_PM_PACKET_PATTERN structure in the
*InformationBuffer*.

### `PatternOffset`

Specifies in bytes the offset from the beginning of the
*InformationBuffer* to the start of the wake-up pattern.

### `PatternSize`

Specifies in bytes the size of the wake-up pattern.

### `PatternFlags`

These flags are reserved.

## Remarks

NDIS_PM_PACKET_PATTERN is supplied in the
*InformationBuffer* of the
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure for following
OIDs:

* [OID_PNP_ADD_WAKE_UP_PATTERN](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pnp-add-wake-up-pattern)

  A protocol driver sends this OID to a miniport driver to specify a wake-up pattern. The wake-up
  pattern, along with its mask, is described by an NDIS_PM_PACKET_PATTERN structure.
* [OID_PNP_REMOVE_WAKE_UP_PATTERN](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pnp-remove-wake-up-pattern)

  A protocol driver sends this OID to a miniport driver to delete a wake-up pattern that it previously
  specified with an OID_PNP_ADD_WAKE_UP_PATTERN request. The wake-up pattern, along with its mask, is
  described by an NDIS_PM_PACKET_PATTERN structure.
* [OID_PNP_WAKE_UP_PATTERN_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pnp-wake-up-pattern-list)

  A protocol uses this OID to request a list of the wake-up patterns currently set for the miniport
  driver's network adapter. Each wake-up pattern, along with its mask, is described by an NDIS_PM_PACKET_PATTERN
  structure.

## See also

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[OID_PNP_ADD_WAKE_UP_PATTERN](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pnp-add-wake-up-pattern)

[OID_PNP_REMOVE_WAKE_UP_PATTERN](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pnp-remove-wake-up-pattern)

[OID_PNP_WAKE_UP_PATTERN_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pnp-wake-up-pattern-list)