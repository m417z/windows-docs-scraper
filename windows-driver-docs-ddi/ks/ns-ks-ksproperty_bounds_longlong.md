# KSPROPERTY_BOUNDS_LONGLONG structure

## Description

The KSPROPERTY_BOUNDS_LONGLONG structure defines the bounds for a 64-bit property.

## Members

### `_SIGNED64`

### `_SIGNED64.SignedMinimum`

Specifies a minimum bound as a signed 64-bit value.

### `_SIGNED64.SignedMaximum`

Specifies a maximum bound as a signed 64-bit value.

### `SignedMinimum`

Specifies a minimum bound as a signed 64-bit value.

### `SignedMaximum`

Specifies a maximum bound as a signed 64-bit value.

### `_UNSIGNED64`

### `_UNSIGNED64.UnsignedMinimum`

Specifies a minimum bound as an unsigned 64-bit value.

### `_UNSIGNED64.UnsignedMaximum`

Specifies a maximum bound as an unsigned 64-bit value.

### `UnsignedMinimum`

Specifies a minimum bound as an unsigned 64-bit value.

### `UnsignedMaximum`

Specifies a maximum bound as an unsigned 64-bit value.

## Remarks

This structure specifies a range of 64-bit values for a property. Use only when the **MembersFlags** member of the relevant [KSPROPERTY_MEMBERSHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_membersheader) is set to KSPROPERTY_MEMBER_RANGES. Use this structure in the **Members** array in the relevant [KSPROPERTY_MEMBERSLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_memberslist) structure.

See the Testcap sample in the Windows Driver Kit (WDK) for examples of usage.

Also see related information in [KS Properties](https://learn.microsoft.com/windows-hardware/drivers/stream/ks-properties).

## See also

[KSPROPERTY_MEMBERSHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_membersheader)

[KSPROPERTY_MEMBERSLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_memberslist)

[KSPROPERTY_VALUES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_values)