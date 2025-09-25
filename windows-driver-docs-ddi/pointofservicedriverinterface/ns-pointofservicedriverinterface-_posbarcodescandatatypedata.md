# _PosBarcodeScanDataTypeData structure

## Description

This structure describes a buffer of barcode symbologies supported by the driver.

## Members

### `dataLengthInBytes`

The size of the buffer that contains the symbologies, including the size of the **PosBarcodeScanDataTypeData** structure.

### `scanDataTypes_0`

The start of the DWORD array of symbologies.

## Remarks

Each symbology in the buffer is represented by a DWORD. The size of the array of symboligies that scanDataTypes_0 points to is `scanDataTypes_0/sizeof(UINT32) - 1;`