# _PosEventDataHeader structure

## Description

This structure describes the scanned image data that is passed to the [BarcodeScannerImagePreviewReceived](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/dn757466(v=vs.85)) event.

## Members

### `EventType`

The type of event. For the [BarcodeScannerImagePreviewReceived](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/dn757466(v=vs.85)) event the value of this field is **BarcodeScannerImagePreviewReceived**.

### `DataLength`

The length, in bytes, of the image preview data.

## Remarks

The image preview bitmap data immediately follows after this structure in memory for *DataLength* bytes.