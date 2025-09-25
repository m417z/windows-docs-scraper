# NdisFIndicateStatus function

## Description

The
**NdisFIndicateStatus** function passes on a filtered status indication from an underlying driver or
originates a status indication.

## Parameters

### `NdisFilterHandle` [in]

The NDIS handle that identifies this filter module. NDIS passed the handle to the filter driver in
a call to the
[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

### `StatusIndication` [in]

A pointer to an
[NDIS_STATUS_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_status_indication) structure
that contains the status information.

## Remarks

Filter drivers can call
**NdisFIndicateStatus** from the
[FilterStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_status) function, to pass on a
filtered status indication to overlying drivers.

To originate status indications, filter drivers call
**NdisFIndicateStatus** without a prior NDIS call to
*FilterStatus*.

A filter driver can call
**NdisFIndicateStatus** after setting its registration attributes and the
[NdisFSetAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfsetattributes) function returns.
The driver must not call
**NdisFIndicateStatus** after it returns from the
[FilterDetach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_detach) function.

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[FilterDetach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_detach)

[FilterStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_status)

[NDIS_STATUS_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_status_indication)

[NdisFSetAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfsetattributes)