# PFNKSPINSETDATAFORMAT callback function

## Description

An AVStream minidriver's *AVStrMiniPinSetDataFormat* routine is called at pin creation time to verify that the previously agreed upon data format is acceptable for this [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure and a match for this [KSDATARANGE](https://learn.microsoft.com/previous-versions/ff561658(v=vs.85)) structure. This routine is also called due to certain types of dynamic format changes, for example the acceptance of a [KSPROPERTY_CONNECTION_PROPOSEDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-connection-proposedataformat) property request.

## Parameters

### `Pin` [in]

Pointer to the [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure for which the data format is changing.

### `OldFormat` [in, optional]

Optional. Pointer to a [KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat) structure. Minidrivers can use this field to determine the data format that the pin was using before this call. If **NULL**, indicates that no data format has been set for the pin and that *Pin's* create dispatch has not yet been made. A **NULL** value here indicates that this routine was called at initialization time for format verification.

### `OldAttributeList` [in, optional]

Optional. Pointer to a [KSMULTIPLE_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksmultiple_item) structure that stores attributes for the previous format.

### `DataRange` [in]

Pointer to a [KSDATARANGE](https://learn.microsoft.com/previous-versions/ff561658(v=vs.85)) structure. The data range for the new format.

### `AttributeRange` [in, optional]

Optional. The attribute range for the new format.

## Return value

Return STATUS_SUCCESS if *Pin*'s **ConnectionFormat** member matches the range that was passed to this routine. Return STATUS_NO_MATCH if **ConnectionFormat** does not match the passed range and the minidriver would like to continue to attempt to find a match with another range. Return an error code of choice if **ConnectionFormat** does not match the passed range and the minidriver does not want to continue to try to find a match with another range. Do not return STATUS_PENDING.

## Remarks

In a ring 3 graph, the Kernel Streaming Proxy module (KsProxy) sets the data format based on the agreed upon connection format or a dynamic format change. KsProxy issues a [KSPROPERTY_CONNECTION_DATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-connection-dataformat) request which, after some initial validation, is translated into this dispatch call to the minidriver. See [Kernel Streaming Proxy](https://learn.microsoft.com/windows-hardware/drivers/ddi/_stream/). For more information, see [KS Data Formats and Data Ranges](https://learn.microsoft.com/windows-hardware/drivers/stream/ks-data-formats-and-data-ranges) and [DataRange Intersections in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/data-range-intersections-in-avstream).

The minidriver specifies the address for *AVStrMiniPinSetDataFormat* in the **SetDataFormat** member of its [KSPIN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_dispatch) structure.

This routine can be called before the pin receives an [IRP_MJ_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create), and minidrivers should be prepared to deal with this situation.

*OldFormat*, *OldAttributeList*, and *AttributeRange* are all optional parameters and can be **NULL**.

This routine is optional.

## See also

[IRP_MJ_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create)

[KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat)

[KSDATARANGE](https://learn.microsoft.com/previous-versions/ff561658(v=vs.85))

[KSMULTIPLE_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksmultiple_item)

[KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin)

[KSPIN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_dispatch)