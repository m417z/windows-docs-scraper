# _BDA_FILTER_TEMPLATE structure

## Description

The BDA_FILTER_TEMPLATE structure describes the template topology for a BDA filter.

## Members

### `pFilterDescriptor`

Points to a KSFILTER_DESCRIPTOR structure that describes a template for a filter for the BDA device.

### `ulcPinPairs`

Number of pairs of pins in the **pPinPairs** array.

### `pPinPairs`

Array of BDA_PIN_PAIRING structures that describe the topology between a pair of the filter's input and output pins.

## See also

[BDA_PIN_PAIRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/ns-bdasup-_bda_pin_pairing)

[BdaCreateFilterFactory](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/nf-bdasup-bdacreatefilterfactory)

[BdaInitFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/nf-bdasup-bdainitfilter)

[KSFILTER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter_descriptor)