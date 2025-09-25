# BdaUninitFilter function

## Description

The **BdaUninitFilter** function removes the BDA filter context from the associated filter instance.

## Parameters

### `pKSFilter` [in]

Points to the filter from which to remove the BDA filter context.

## Return value

Returns STATUS_SUCCESS or an appropriate error code.

## Remarks

The **BdaUninitFilter** function exists only to support legacy drivers and is, therefore, obsolete. That is, new BDA minidriver implementations should not call **BdaUninitFilter**.

In Windows XP and later, the BDA support driver (*Bdasup.sys*) automatically handles removing the BDA filter context associated with a filter instance. When a BDA minidriver calls [BdaInitFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/nf-bdasup-bdainitfilter), the BDA support driver creates its own BDA filter context. This BDA filter context is hidden from the BDA minidriver. However, when required, the BDA support driver can access this BDA filter context. The BDA support driver adds a pointer to this BDA filter context to the object bag for the associated [KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter) object. When the associated KSFILTER object is destroyed, AVStream requests that the BDA support driver delete this BDA filter context from the object bag. In this way, the BDA support driver can destroy this BDA filter context without requiring intervention by the BDA minidriver.

## See also

[BdaInitFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/nf-bdasup-bdainitfilter)

[KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter)