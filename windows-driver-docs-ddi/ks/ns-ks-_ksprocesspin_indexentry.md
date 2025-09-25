# _KSPROCESSPIN_INDEXENTRY structure

## Description

The KSPROCESSPIN_INDEXENTRY structure is used in [Filter-Centric Processing](https://learn.microsoft.com/windows-hardware/drivers/stream/filter-centric-processing) to bring together all of the input and output pins in one context.

## Members

### `Pins`

A pointer to an array of [KSPROCESSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksprocesspin) structures. The array contains a listing of the instances of the given pin.

### `Count`

This member specifies the number of process pins in *Pins* that are currently instantiated.

## Remarks

This pointer table is indexed in order of the pins described in the pin descriptor table for the corresponding filter. The first pin described in the descriptor table has the first entry in the index table passed to the processing dispatch. See the processing dispatch in [KSPIN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_dispatch).

For more information, see [Filter-Centric Processing](https://learn.microsoft.com/windows-hardware/drivers/stream/filter-centric-processing).

## See also

[KSPROCESSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksprocesspin)