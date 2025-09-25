# KSPROPERTY_STEPPING_LONG structure

## Description

The KSPROPERTY_STEPPING_LONG structure defines the valid range of values for a 32-bit property.

## Members

### `SteppingDelta`

Specifies the step value that should be used to create legal values within the range defined in **Bounds**.

### `Reserved`

Reserved for system use.

### `Bounds`

A structure of type [KSPROPERTY_BOUNDS_LONG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_bounds_long) that specifies the range of values over which the **SteppingDelta** is valid.

## Remarks

The [KSPROPERTY_MEMBERSLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_memberslist) structure may contain structures of this type in its **Members** array.

See the Testcap sample in the Windows Driver Kit (WDK) for examples of usage.

For more information, see [KS Properties](https://learn.microsoft.com/windows-hardware/drivers/stream/ks-properties).

## See also

[KSPROPERTY_BOUNDS_LONG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_bounds_long)

[KSPROPERTY_MEMBERSLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_memberslist)