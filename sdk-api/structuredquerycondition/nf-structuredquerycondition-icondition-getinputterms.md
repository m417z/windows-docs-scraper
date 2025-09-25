# ICondition::GetInputTerms

## Description

For a leaf node, **ICondition::GetInputTerms** retrieves information about what parts (or ranges) of the input string produced the property, the operation, and the value for the search condition node.

## Parameters

### `ppPropertyTerm` [out, optional]

Type: **[IRichChunk](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-irichchunk)****

Receives a pointer to an [IRichChunk](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-irichchunk) interface that provides information about what part of the input string produced the property of the leaf node, if that can be determined; otherwise, this parameter is set to **NULL**.

### `ppOperationTerm` [out, optional]

Type: **[IRichChunk](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-irichchunk)****

Receives a pointer to an [IRichChunk](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-irichchunk) interface that provides information about what part of the input string produced the operation of the leaf node, if that can be determined; otherwise, this parameter is set to **NULL**.

### `ppValueTerm` [out, optional]

Type: **[IRichChunk](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-irichchunk)****

Receives a pointer to an [IRichChunk](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-irichchunk) interface that provides information about what part of the input string produced the value of the leaf node, if that can be determined; otherwise, this parameter is set to **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Any or all of the parameters *ppPropertyTerm*, *ppOperationTerm* and *ppValueTerm* can be **NULL**.

Each [IRichChunk](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-irichchunk) object retrieved by this method represents a range of tokens from the input string. The range tokens identifies the substring that produced the property, operation, or value of the input string. The **IRichChunk**'s [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) out parameter is not used.

## See also

[CONDITION_OPERATION](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_operation)

[CONDITION_TYPE](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_type)

[ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition)

[ICondition2](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition2)

**Reference**