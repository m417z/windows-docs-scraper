# _MsrStatusUpdateType enumeration

## Description

This enumeration defines the constants that indicate the magnetic stripe reader (MSR) status.

## Constants

### `MsrStatusUpdateType_Online`

The device is powered on. This is valid if [UnifiedPosPowerReportingType](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicecommontypes/ne-pointofservicecommontypes-driverunifiedpospowerreportingtype) is **Standard** or **Advanced**.

### `MsrStatusUpdateType_Off`

The device is powered off or is detached from the terminal. This is valid if [UnifiedPosPowerReportingType](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicecommontypes/ne-pointofservicecommontypes-driverunifiedpospowerreportingtype) is **Advanced**.

### `MsrStatusUpdateType_Offline`

The device is powered on but is not ready, or is unable, to respond to requests. This is valid if [UnifiedPosPowerReportingType](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicecommontypes/ne-pointofservicecommontypes-driverunifiedpospowerreportingtype) is **Advanced**.

### `MsrStatusUpdateType_OffOrOffline`

The device is either off or offline. This is valid if [UnifiedPosPowerReportingType](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicecommontypes/ne-pointofservicecommontypes-driverunifiedpospowerreportingtype) is **Standard**.

### `MsrStatusUpdateType_Unauthenticated`

The device is not authenticated. This is valid if the device supports authentication.

### `MsrStatusUpdateType_Authenticated`

The device is authenticated. This is valid if the device supports authentication.

### `MsrStatusUpdateType_Extended`

Vendor-specific status information. Reported in IMagneticStripeReaderStatusUpdatedEventArgs.ExtendedStatus.