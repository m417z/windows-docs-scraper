# KsDeviceGetBusData function

## Description

The **KsDeviceGetBusData** function reads data from the bus where the given AVStream device resides.

## Parameters

### `Device` [in]

A pointer to the [KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice) structure representing the given AVStream device for which data from the bus should be read.

### `DataType` [in]

This parameter indicates the type of bus data to be read. Zero corresponds to configuration space. For further information, see the discussion of **WhichSpace** in the reference page for [IRP_MN_READ_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-read-config).

### `Buffer` [in]

A pointer to a buffer that receives the data read from the bus. Must be at least as large as *Length*.

### `Offset` [in]

This parameter contains the byte offset in the space specified by *DataType* from which data is read.

### `Length` [in]

This parameter specifies the number of bytes to read into *Buffer*.

## Return value

**KsDeviceGetBusData** returns the number of bytes actually read from the bus. If an errors occurs, this value is zero.

## Remarks

Depending on the driver for the bus where the specified device resides, there are two possible behaviors and restriction sets on this function. If the given bus driver supports the bus interface standard (usually PCI), call this function at either IRQL = PASSIVE_LEVEL or DISPATCH_LEVEL. After such a call, **KsDeviceGetBusData** returns the actual number of bytes read from the requested space. If, however, the given bus driver does not support the bus interface standard, then AVStream communicates with the bus driver through [IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver). Note that this restricts use of **KsDeviceGetBusData** to IRQL = PASSIVE_LEVEL and also means that the return value is either 0, in the case of failure, or equal to *Length* if data acquisition was successful*.*

To ensure compatibility, minidriver writers may want to restrict use of **KsDeviceGetBusData** to IRQL = PASSIVE_LEVEL.

## See also

[IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver)

[KsDeviceSetBusData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksdevicesetbusdata)