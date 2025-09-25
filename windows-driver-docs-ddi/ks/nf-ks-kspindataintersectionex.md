# KsPinDataIntersectionEx function

## Description

The **KsPinDataIntersectionEx** function handles the [KSPROPERTY_PIN_DATAINTERSECTION](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-pin-dataintersection) through a callback function.

## Parameters

### `Irp` [in]

Specifies the IRP that describes the property request.

### `Pin` [in]

Specifies the specific property that is being queried.

### `Data` [out]

Specifies the pin property-specific data.

### `DescriptorsCount` [in]

Specifies the number of descriptor structures.

### `Descriptor` [in]

Specifies the pointer to the list of pin information structures.

### `DescriptorSize` [in]

Size of the descriptor structures, in bytes.

### `IntersectHandler` [in, optional]

Contains the optional minidriver-defined [KStrIntersectHandlerEx](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff567185(v=vs.85)) callback function to compare data ranges.

### `HandlerContext` [in, optional]

Optional context that is supplied to the handler.

## Return value

Returns STATUS_SUCCESS; otherwise, an error specific to the property that is being handled.

## Remarks

**KsPinDataIntersectionEx** is very similar to **KsPinDataIntersection**, except for some of the following slight differences:

* In **KsPinDataIntersectionEx**, the size of the descriptor is passed, a feature that allows extended descriptors.
* The data intersection callback function is prototyped differently in the extended version (NTSTATUS Callback (*Context*, *Irp*, *Pin*, *DataRange*, *MatchingDataRange*, *DataBufferSize*, *Data*, *DataSize*)) versus **KsPinDataIntersection** (NTSTATUS Callback (*Irp*, *Pin*, *DataRange*, *Data*)).
* The output buffer (*Data*) length is passed as a parameter to the data intersection callback function (*DataBufferSize*) rather than being extracted from the current I/O stack location.
* The data intersection callback function is passed a *Context* parameter (the same *Context* parameter passed to **KsPinDataIntersectionEx**).
* The size of the resultant format is passed back in *DataSize* instead of *Irp*->IoStatus.Information.

These differences excepted, **KsPinDataIntersection** and **KsPinDataIntersectionEx** operate similarly.

## See also

[KStrIntersectHandlerEx](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff567185(v=vs.85))