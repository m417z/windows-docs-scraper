typedef struct _BarcodeSymbologyAttributesData {
  BarcodeSymbology                 Symbology;
  UINT32                           IsCheckDigitValidationSupported;
  UINT32                           IsCheckDigitValidationEnabled;
  UINT32                           IsCheckDigitTransmissionSupported;
  UINT32                           IsCheckDigitTransmissionEnabled;
  UINT32                           IsDecodeLengthSupported;
  BarcodeSymbologyDecodeLengthType DecodeLengthType;
  UINT32                           DecodeLength1;
  UINT32                           DecodeLength2;
} BarcodeSymbologyAttributesData;