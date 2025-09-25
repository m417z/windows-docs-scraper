# STOR_UNIT_CONTROL_QUERY_BUS_TYPE structure

## Description

**STOR_UNIT_CONTROL_QUERY_BUS_TYPE** is the structure pointed to by the **Parameters** parameter when a miniport's [**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control) routine is called with a **ControlType** of **ScsiUnitQueryBusType**.

## Members

### `Address`

Pointer to a [**STOR_ADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsi/ns-scsi-_stor_address) structure that holds a storage device address.

### `BusType`

The bus type specified by the miniport for the unit. This value must be one of the enum values defined in [**STORAGE_BUS_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-storage_bus_type).

## Remarks

A miniport can use it to specify a device bus type if the device and controller have different bus types.

## See also

[**STOR_ADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsi/ns-scsi-_stor_address)

[**STORAGE_BUS_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-storage_bus_type)