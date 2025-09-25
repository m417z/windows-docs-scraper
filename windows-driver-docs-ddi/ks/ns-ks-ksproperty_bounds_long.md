# KSPROPERTY_BOUNDS_LONG structure

## Description

The KSPROPERTY_BOUNDS_LONG structure defines the bounds for a 32-bit property.

## Members

### `_SIGNED`

### `_SIGNED.SignedMinimum`

### `_SIGNED.SignedMaximum`

### `SignedMinimum`

Specifies a minimum bound as a signed 32-bit value.

### `SignedMaximum`

Specifies a maximum bound as a signed 32-bit value.

### `_UNSIGNED`

### `_UNSIGNED.UnsignedMinimum`

### `_UNSIGNED.UnsignedMaximum`

### `UnsignedMinimum`

Specifies a minimum bound as an unsigned 32-bit value.

### `UnsignedMaximum`

Specifies a maximum bound as an unsigned 32-bit value.

## Remarks

This structure specifies a range of 32-bit values for a property. Use only when the **MembersFlags** member of the relevant [KSPROPERTY_MEMBERSHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_membersheader) is set to KSPROPERTY_MEMBER_RANGES. Use this structure in the **Members** array in the relevant [KSPROPERTY_MEMBERSLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_memberslist) structure.

See the Testcap sample in the Windows Driver Kit (WDK) for examples of usage.

Also see related information in [KS Properties](https://learn.microsoft.com/windows-hardware/drivers/stream/ks-properties).

## See also

[KSPROPERTY_MEMBERSHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_membersheader)

[KSPROPERTY_MEMBERSLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_memberslist)

[KSPROPERTY_VALUES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_values)