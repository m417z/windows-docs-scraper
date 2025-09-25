# IInkRecognitionAlternate::GetPropertyValue

## Description

Retrieves the value of a specified property of the alternate.

## Parameters

### `PropertyType` [in]

Specifies which property of the alternate to return, as one of the GUIDs from the [RecognitionProperty](https://learn.microsoft.com/windows/desktop/tablet/recognitionproperty-constants) object.

For more information about the BSTR data type, see [Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library).

### `PropertyValue` [out, retval]

Upon return, contains the value of the property type as an array of bytes. this value is interpreted differently for each property type.

| RecognitionProperty Type | Description |
| --- | --- |
| **ConfidenceLevel** | CONFIDENCE_LEVEL enumeration type. |
| **HotPoint** | POINT. |
| **LineMetrics** | LATTICE_METRICS structure. |
| **LineNumber** | ULONG. |
| **MaximumStrokeCount** | Not used. |
| **PointsPerInch** | Not used. |
| **Segmentation** | Not a value, returns TPC_E_INVALID_PROPERTY. |
| **S_OK** | Success. |

For more information about the VARIANT structure, see [Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INK_EXCEPTION** | An exception occurred while processing. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **CO_E_CLASSSTRING** | Invalid GUID format. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | The flag is invalid. |
| **E_OUTOFMEMORY** | Cannot allocate memory to complete the operation. |

## Remarks

 Use this method to obtain property values for [RecognitionProperty](https://learn.microsoft.com/windows/desktop/tablet/recognitionproperty-constants) objects that have no corresponding helper property, such as the [Confidence](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-get_confidence) and [LineNumber](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-get_linenumber) properties.

## See also

[AlternatesWithConstantPropertyValues Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-alternateswithconstantpropertyvalues)

[IInkRecognition Alternate Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionalternate)

[RecognitionProperty Constants](https://learn.microsoft.com/windows/desktop/tablet/recognitionproperty-constants)