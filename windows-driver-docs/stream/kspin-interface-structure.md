# KSPIN_INTERFACE structure

The **KSPIN_INTERFACE** structure describes a specific interface within an interface set.

## Members

`Set`

Specifies the GUID that specifies this interface set.

`Id`

Specifies the ID number of this particular interface within the interface set.

`Flags`

Reserved for system use.

## Remarks

The **KSPIN_INTERFACE** structure is an alias for the [**KSIDENTIFIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksidentifier) structure. As such, their definitions are identical.

## Requirements

**Header:** ks.h (include Ks.h)

## See also

[**KSIDENTIFIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksidentifier)