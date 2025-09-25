# KsDeviceSetBusData function

## Description

The **KsDeviceSetBusData** function writes data to the bus on which the specified AVStream device resides.

## Parameters

### `Device` [in]

A pointer to a [KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice) structure. This routine attempts to write data to the bus on which this device resides.

### `DataType` [in]

This parameter indicates the type of bus data to be written. Zero corresponds to configuration space. For further information, see the discussion of **WhichSpace** in the reference page for [IRP_MN_READ_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-read-config).

### `Buffer` [in]

A pointer to a buffer that contains the data to write to the bus. Number of bytes in the buffer must be equal or greater than *Length*.

### `Offset` [in]

This parameter contains the byte offset into the space specified by *DataType* where data is written.

### `Length` [in]

This parameter specifies the number of bytes of data to write to the bus from *Buffer.*

## Return value

**KsDeviceSetBusData** returns the number of bytes actually written to the bus. In the case of an error, the routine returns zero. See details below in the Remarks section.

## Remarks

This function performs differently depending on the driver for the bus on which the specified device resides. If the bus driver supports the bus interface standard (usually PCI), call this function at either IRQL = PASSIVE_LEVEL or DISPATCH_LEVEL. After such a call, **KsDeviceSetBusData** returns the actual number of bytes written to the requested space.

If the bus driver does not support the bus interface standard, AVStream communicates with the bus driver using [IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver). In this case, call **KsDeviceSetBusData** at IRQL = PASSIVE_LEVEL. The return value is either zero, in the case of failure, or equal to *Length* if the data was written successfully.

Drivers running on Windows 2000 and later can make this call at IRQL = DISPATCH_LEVEL. However, to ensure compatibility, minidriver writers may want to restrict use of **KsDeviceSetBusData** to IRQL = PASSIVE_LEVEL.

## See also

[IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver)

[KsDeviceGetBusData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksdevicegetbusdata)