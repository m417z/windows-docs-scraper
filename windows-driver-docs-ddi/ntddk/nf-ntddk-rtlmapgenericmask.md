# RtlMapGenericMask function

## Description

The **RtlMapGenericMask** routine determines the nongeneric access rights specified by an ACCESS_MASK.

## Parameters

### `AccessMask` [in, out]

Pointer to an [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) variable. The routine updates this to contain only those access rights that are not also granted by any GENERIC_*XXX* access rights originally specified the variable. The routine also clears any GENERIC_*XXX* bits that are set.

### `GenericMapping` [in]

Pointer to a [GENERIC_MAPPING](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_generic_mapping) structure that describes the specific access rights that correspond to each generic access right.

## Return value

None

## See also

[GENERIC_MAPPING](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_generic_mapping)