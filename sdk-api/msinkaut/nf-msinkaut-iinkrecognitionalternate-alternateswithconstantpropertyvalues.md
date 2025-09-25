# IInkRecognitionAlternate::AlternatesWithConstantPropertyValues

## Description

Retrieves a [IInkRecognitionAlternates](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionalternates) collection, which are a division of the [IInkRecognitionAlternate](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionalternate) object on which this method is called.

## Parameters

### `PropertyType` [in]

Specifies a string value that identifies the property. For a list of the properties that can be used, see [RecognitionProperty](https://learn.microsoft.com/windows/desktop/tablet/recognitionproperty-constants).

For more information about the BSTR data type, see [Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library).

### `AlternatesWithConstantPropertyValues` [out, retval]

When this method returns, contains an [IInkRecognitionAlternates](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionalternates) collection which is made up of a division of the alternate on which this method is called. Each [IInkRecognitionAlternate](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionalternate) object in the collection contains adjacent recognition segments which have the same property value for the *propertyType* parameter.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INVALIDARG** | The recognition range is invalid. |
| **E_INK_EXCEPTION** | An exception occurred while processing. |
| **E_OUTOFMEMORY** | Cannot allocate memory to complete the operation. |

## Remarks

Each alternate in the collection contains adjacent recognition segments which have the same property value for the property passed into the method.

For example, you can return alternates that divide the original alternate by:

* Level of confidence boundaries-strong, intermediate, or poor-in the recognition result.
* Line boundaries.
* Recognition segment boundaries.

For a complete list of property types, see [RecognitionProperty](https://learn.microsoft.com/windows/desktop/tablet/recognitionproperty-constants).

**Note** The recognizer determines the segmentation of strokes into the recognition segments. Some recognition segments, such as spaces, may correspond to an empty [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection.

**Note** The recognizer determines the ordering of the recognition segments. Therefore, adjacent recognition segments may be based on the order in which the ink was drawn or based on location, such as whether it is positioned left-to-right, positioned top-to-bottom, and so on.

The [ConfidenceAlternates](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-get_confidencealternates) property is an alternative to the **AlternatesWithConstantPropertyValues** method, where [ConfidenceLevel](https://learn.microsoft.com/windows/desktop/tablet/recognitionproperty-constants) is the RecognitionProperty that separates the alternates in the returned recognition alternates collection.

The [LineAlternates](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-get_linealternates) property is an alternative to the **AlternatesWithConstantPropertyValues** method, where [LineNumber](https://learn.microsoft.com/windows/desktop/tablet/recognitionproperty-constants) is the RecognitionProperty that separates the alternates in the returned recognition alternates collection.

**Note** The **AlternatesWithConstantPropertyValues** method, the [LineAlternates](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-get_linealternates) property, and the [ConfidenceAlternates](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-get_confidencealternates) property of the [IInkRecognitionAlternate](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionalternate) object function differently than the [AlternatesFromSelection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms698186(v=vs.85)) method of the [IInkRecognitionResult](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionresult) object. **AlternatesFromSelection** returns a collection of alternates for the requested segments of the recognition result.

## See also

[ConfidenceAlternates Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-get_confidencealternates)

[GetAlternatesFromSelection Method](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms698186(v=vs.85))

[GetPropertyValue Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-getpropertyvalue)

[IInkRecognitionAlternate Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionalternate)

[IInkRecognitionAlternates Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionalternates)

[IInkRecognitionResult Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionresult)

[LineAlternates Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-get_linealternates)