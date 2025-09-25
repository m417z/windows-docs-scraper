# _PosBarcodeScannerDataReceivedEventData structure

## Description

This structure contains the scanned data that is passed to the [BarcodeScannerDataReceived](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/dn757463(v=vs.85)) event.

## Members

### `Header`

The [PosEventDataHeader](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/dn772232(v=vs.85)) header information for this event.

### `DataType`

Indicates which [BarcodeSymbology](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicecommontypes/ne-pointofservicecommontypes-_barcodesymbology) is associated with the scan data.

### `ScanDataLength`

Indicates the number of bytes of raw scanned data.

### `ScanDataLabelLength`

Indicates the number of bytes of decoded scan data. A label is the decoded scan data in which the header and footer information has been removed, leaving only the raw scanner data.

## Remarks

*ScanDataLength* bytes of scan data immediately follows the *PosBarcodeScannerDataReceivedEventData* structure, followed by *ScanDataLabelLength* bytes of label data.