# _USB_BUS_INFORMATION_LEVEL_0 structure

## Description

The **USB_BUS_INFORMATION_LEVEL_0** structure is used in conjunction with the [QueryBusInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbbusif/nc-usbbusif-pusb_busiffn_query_bus_information) interface routine to report information about the bus.

## Members

### `TotalBandwidth`

Specifies the total bandwidth, in bits per second, available on the bus.

### `ConsumedBandwidth`

Specifies the mean bandwidth that is already in use, in bits per second.

## Remarks

Caller must set the *Level* parameter of the [QueryBusInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbbusif/nc-usbbusif-pusb_busiffn_query_bus_information) routine to zero.

For more information about how to obtain the proper level of USB interface, see [USB Routines](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff540046(v=vs.85)).

## See also

[QueryBusInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbbusif/nc-usbbusif-pusb_busiffn_query_bus_information)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)