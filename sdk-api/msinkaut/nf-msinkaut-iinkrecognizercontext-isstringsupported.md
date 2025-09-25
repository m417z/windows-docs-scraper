# IInkRecognizerContext::IsStringSupported

## Description

Indicates whether the system dictionary, user dictionary, or [word list](https://learn.microsoft.com/windows/desktop/tablet/inkwordlist-class) contain a specified string.

## Parameters

### `String` [in]

The string to look up in the dictionaries and word list.

For more information about the BSTR data type, see [Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library).

### `Supported` [out, retval]

When this method returns, contains **VARIANT_TRUE** if the string is in the dictionary or word list; otherwise **VARIANT_FALSE**.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | One of the dictionaries contains the string. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INVALIDARG** | Invalid input string. |
| **E_INK_EXCEPTION** | An exception occurred while processing. |
| **E_OUTOFMEMORY** | Cannot allocate memory operation. |
| **E_UNEXPECTED** | Unexpected parameter or property type. |

## Remarks

This method considers all flags and factoid, among other things, that give context to the string that is being tested.

This method does not search the user dictionary if you specify a [word list](https://learn.microsoft.com/windows/desktop/tablet/inkwordlist-class) for the context. The recognizer uses the speech dictionary in Microsoft Office XP.

Use the [Factoid](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-get_factoid) property to limit the search to the system dictionary or the word list that is associated with the context. For example, to limit the search to the system dictionary, specify the [SystemDictionary](https://learn.microsoft.com/windows/desktop/tablet/factoid-constants) factoid. To improve the results, you may also need to set the [RecognitionFlags](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-get_recognitionflags) property.

## See also

[Factoid Property [InkRecognizeContext Class]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-get_factoid)

[IInkRecognizerContext](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkrecognizercontext)

[InkRecognizerContext Class](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class)

[RecognitionFlags Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-get_recognitionflags)