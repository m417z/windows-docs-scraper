# _PosBarcodeScannerErrorOccurredEventData structure

## Description

This structure contains the error data that is passed to the [BarcodeScannerErrorOccurred](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/dn757464(v=vs.85)) event.

## Members

### `Header`

The [PosEventDataHeader](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/dn772232(v=vs.85)) structure that describes the amount of memory, in bytes, of the **PosBarcodeScannerErrorOccurredEventData** structure and trailing error message and scan data.

### `IsRetriable`

Indicates whether [ReadFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-readfile) can be called again to read this event

### `Severity`

Contains a value in the [UnifiedPosErrorSeverity](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicecommontypes/ne-pointofservicecommontypes-driverunifiedposerrorseverity) enumeration indicating the severity of the error.

### `VendorErrorCode`

Contains a vendor-specific error code.

### `Reason`

Contains a value in the [UnifiedPosErrorReason](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicecommontypes/ne-pointofservicecommontypes-driverunifiedposerrorreason) enumeration indicating the reason for the error.

### `ExtendedReason`

Contains additional data about the reason for the error.

### `MessageLength`

Indicates the length, in bytes, of the error message.

### `PartialData`

If a scanning error occurs, and some scan data was obtained, the partial scan data will be available in this parameter.

## Remarks

The error data should fill the buffer as shown in the following table (in order).

| Data | Length in bytes |
|--|--|
| **PosBarcodeScannerErrorOccurredEventData** structure | sizeof(**PosBarcodeScannerErrorOccurredEventData**) |
| Error message text | **MessageLength** |
| Partial scan data | **PartialData.ScanDataLength** |
| Label data | **PartialData.ScanDataLabelLength** |