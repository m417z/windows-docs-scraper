# IInkRecognitionAlternates::Item

## Description

Retrieves the [IInkRecognitionAlternate](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionalternate) object at the specified index within the [IInkRecognitionAlternates](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionalternates) collection.

## Parameters

### `Index` [in]

The zero-based index of the [IInkRecognitionAlternate](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionalternate) object to get.

### `InkRecoAlternate` [out, retval]

When this method returns, contains a pointer to the [IInkRecognitionAlternate](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionalternate) object at the specified index within the [IInkRecognitionAlternates](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionalternates) collection.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_FAIL** | An unspecified error occurred. |
| **CO_E_CLASSTRING** | Invalid GUID format. |
| **DISP_E_TYPEMISMATCH** | One of the parameters is not a valid VARIANT type. |
| **E_INVALIDARG** | Invalid argument. |
| **E_UNEXPECTED** | Unexpected parameter or property type. |
| **REGDB_CLASSNOTREG** | Type object not registered. |
| **E_OUTOFMEMORY** | Cannot allocate memory to complete the operation. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **TPC_E_RECOGNIZER_NOT_REGISTERED** | The recognizers registry key is corrupted or your environment does not support handwriting recognition. |

## Remarks

An error occurs if the index doesn't match any existing member of the collection.

## See also

[IInkRecognitionAlternate Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionalternate)

[IInkRecognitionAlternates Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionalternates)