# _BarcodeStatus enumeration

## Description

This enumeration indicates barcode scanner status values.

## Constants

### `BarcodeStatusUpdateType_Online`

The device is online. This is valid if [UnifiedPosPowerReportingType](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicecommontypes/ne-pointofservicecommontypes-driverunifiedpospowerreportingtype) is **Standard** or **Advanced**.

### `BarcodeStatusUpdateType_Off`

The device power is off or detached from the terminal. This is valid if [UnifiedPosPowerReportingType](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicecommontypes/ne-pointofservicecommontypes-driverunifiedpospowerreportingtype) is **Advanced**.

### `BarcodeStatusUpdateType_Offline`

The device power is on, but it is not ready or unable to respond to requests. This is valid if [UnifiedPosPowerReportingType](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicecommontypes/ne-pointofservicecommontypes-driverunifiedpospowerreportingtype) is **Advanced**.

### `BarcodeStatusUpdateType_OffOrOffline`

The device power is off or the device is offline. This is valid if [UnifiedPosPowerReportingType](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicecommontypes/ne-pointofservicecommontypes-driverunifiedpospowerreportingtype) is **Standard**.

### `BarcodeStatusUpdateType_Extended`

Vendor specific status information.