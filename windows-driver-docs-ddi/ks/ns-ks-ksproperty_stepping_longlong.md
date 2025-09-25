# KSPROPERTY_STEPPING_LONGLONG structure

## Description

The KSPROPERTY_STEPPING_LONGLONG structure defines the valid range of values for a 64-bit property.

## Members

### `SteppingDelta`

Specifies the step value that should be used to create legal values within the range defined in **Bounds**.

### `Bounds`

Specifies a structure of type [KSPROPERTY_BOUNDS_LONGLONG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_bounds_longlong) that specifies the range of values over which the **SteppingDelta** is valid.

## Remarks

The [KSPROPERTY_MEMBERSLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_memberslist) structure may contain structures of this type in its **Members** array.

See the Testcap sample in the Windows Driver Kit (WDK) for examples of usage.

For more information, see [KS Properties](https://learn.microsoft.com/windows-hardware/drivers/stream/ks-properties).

## See also

[KSPROPERTY_BOUNDS_LONGLONG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_bounds_longlong)

[KSPROPERTY_MEMBERSLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_memberslist)