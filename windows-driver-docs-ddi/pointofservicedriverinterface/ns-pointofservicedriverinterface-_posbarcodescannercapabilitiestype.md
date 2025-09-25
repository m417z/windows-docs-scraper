# _PosBarcodeScannerCapabilitiesType structure

## Description

This structure defines the type of scanner capabilities that a device supports such as whether the device supports statistics reporting and image preview.

## Members

### `PowerReportingType`

A [UnifiedPosPowerReportingType](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicecommontypes/ne-pointofservicecommontypes-driverunifiedpospowerreportingtype) that indicates whether the device supports standard or advanced power reporting.

### `IsStatisticsReportingSupported`

Indicates whether [IOCTL_POINT_OF_SERVICE_RETRIEVE_STATISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ni-pointofservicedriverinterface-ioctl_point_of_service_retrieve_statistics) is supported.

### `IsStatisticsUpdatingSupported`

Indicates whether [IOCTL_POINT_OF_SERVICE_UPDATE_STATISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ni-pointofservicedriverinterface-ioctl_point_of_service_update_statistics) is supported.

### `IsImagePreviewSupported`

Indicates whether image data can be obtained from the barcode scanner device (in other words, whether [BarcodeScannerImagePreviewReceived](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/dn757466(v=vs.85)) events will be sent by the driver).