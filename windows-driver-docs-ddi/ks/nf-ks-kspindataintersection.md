# KsPinDataIntersection function

## Description

The **KsPinDataIntersection** function handles the [KSPROPERTY_PIN_DATAINTERSECTION](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-pin-dataintersection) property through a callback function and performs much of the initial validation of the parameters that are passed. **KsPinDataIntersection** calls the minidriver-defined [KStrIntersectHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksintersecthandler) callback function with each potential data range after matching it to the list of data ranges assigned to that pin factory.

## Parameters

### `Irp` [in]

Specifies the IRP that describes the property request.

### `Pin` [in]

Specifies the specific property that is being queried.

### `Data` [out, optional]

Specifies the pin property-specific data.

### `DescriptorsCount` [in]

Specifies the number of descriptor structures.

### `Descriptor` [in]

Specifies the pointer to the list of pin information structures.

### `IntersectHandler` [in]

Specifies the minidriver-defined [KStrIntersectHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksintersecthandler) callback function to compare a data range.

## Return value

The **KsPinDataIntersection** function returns STATUS_SUCCESS if a matching range is found, STATUS_NO_MATCH if no matching range was found, or an error specific to the property being handled. The minidriver-defined *KStrIntersectHandler* intersection handler provided to **KsPinDataIntersection** is called with each data range supplied by the caller until either a match is found or an error occurs.

Note that the minidriver-defined [KStrIntersectHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksintersecthandler) callback function has its own set of return values.

## Remarks

A match can occur under three conditions: if the major format of the range passed is a wildcard or matches a pin factory range, if the subformat is a wildcard or matches, and if the specifier is a wildcard or matches. Since the data range size may be variable, it is not validated beyond checking that it is at least the size of a [KSDATARANGE](https://learn.microsoft.com/previous-versions/ff561658(v=vs.85)) structure.

## See also

[KSDATARANGE](https://learn.microsoft.com/previous-versions/ff561658(v=vs.85))

[KStrIntersectHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksintersecthandler)