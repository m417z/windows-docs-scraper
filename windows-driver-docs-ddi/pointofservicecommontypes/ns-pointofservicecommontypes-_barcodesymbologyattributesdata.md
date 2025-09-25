# _BarcodeSymbologyAttributesData structure

## Description

The **BarcodeSymbologyAttributesData** structure contains the attribute information for a barcode symbology.

## Members

### `Symbology`

The barcode symbology to set or get attributes to or from.

For more information, see the [BarcodeSymbology](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicecommontypes/ne-pointofservicecommontypes-_barcodesymbology) enumeration topic.

### `IsCheckDigitValidationSupported`

Indicates whether the barcode scanner supports check digit of the symbology. Non-zero if supported.

### `IsCheckDigitValidationEnabled`

Indicates whether the target barcodes are expected to contain a check digit.

Some barcodes may have the last digit as a validation digit to ensure decoding accuracy. Barcode scanners may choose to support the feature or not. Non-zero if enabled.

### `IsCheckDigitTransmissionSupported`

Indicates whether the barcode scanner supports check digit transmission. Non-zero if supported.

### `IsCheckDigitTransmissionEnabled`

Indicates whether the check digit is transmitted along with the decoded data. Non-zero if enabled.

### `IsDecodeLengthSupported`

Indicates whether the barcode scanner supports setting decode length for the symbology.

For example, the API can be used to set to read barcodes of decode length between 2 and 8. This helps with filtering the target barcodes. Non-zero if supported.

### `DecodeLengthType`

 The decode length type, which can be set to support a range, two discrete values, or be set to any length.
For more information, see the [BarcodeSymbologyDecodeLengthType](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicecommontypes/ne-pointofservicecommontypes-_barcodesymbologydecodelengthtype).

### `DecodeLength1`

The first value in a range, or the first discrete value.

### `DecodeLength2`

The last value in a range, or a second discrete value.