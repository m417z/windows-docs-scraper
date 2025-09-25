# BdaInitFilter function

## Description

The **BdaInitFilter** function initializes the BDA filter context associated with a filter instance.

## Parameters

### `pKSFilter` [in]

Points to the filter in which to initialize the BDA filter context.

### `pBdaFilterTemplate` [in]

Points to a [BDA_FILTER_TEMPLATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/ns-bdasup-_bda_filter_template) structure that describes the filter template for the BDA device. To determine topology for and configure the initialized filter, the network provider uses information referenced in this BDA_FILTER_TEMPLATE structure.

## Return value

Returns STATUS_SUCCESS or an appropriate error code.

## Remarks

A BDA minidriver calls the **BdaInitFilter** function to initialize an instance of a filter using a specific BDA filter template and a filter factory that was previously created through a call to the [BdaCreateFilterFactory](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/nf-bdasup-bdacreatefilterfactory) function. The BDA minidriver can subsequently use this filter instance in calls to other BDA support functions, such as, [BdaCreatePin](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/nf-bdasup-bdacreatepin).

When a BDA minidriver calls **BdaInitFilter**, the BDA support driver (*Bdasup.sys*) creates its own BDA filter context. This BDA filter context is hidden from the BDA minidriver. However, when required, the BDA support driver can access this BDA filter context. The BDA support driver adds a pointer to this BDA filter context to the object bag for the associated [KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter) object. When the associated KSFILTER object is destroyed, AVStream requests that the BDA support driver delete this BDA filter context from the object bag. In this way, the BDA support driver can destroy this BDA filter context without requiring intervention by the BDA minidriver.

## See also

[BDA_FILTER_TEMPLATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/ns-bdasup-_bda_filter_template)

[BdaCreateFilterFactory](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/nf-bdasup-bdacreatefilterfactory)

[BdaCreatePin](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/nf-bdasup-bdacreatepin)

[KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter)