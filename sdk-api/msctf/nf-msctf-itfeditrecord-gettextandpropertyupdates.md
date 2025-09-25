# ITfEditRecord::GetTextAndPropertyUpdates

## Description

Obtains an enumerator that contains a collection of range objects that cover the specified properties and/or text that changed during the edit session.

## Parameters

### `dwFlags` [in]

Contains a combination of the following values that specify the behavior of this method.

| Value | Meaning |
| --- | --- |
| **0** | Specifies that the method will obtain a collection of range objects that cover the specified properties changed during the edit session. *prgProperties* cannot be **NULL** and *cProperties* must be greater than zero. |
| **TF_GTP_INCL_TEXT** | Specifies that the method will obtain the collection of range objects that cover the text changed during the edit session. |

### `prgProperties` [in]

Pointer to an array of **GUID** values that identify the properties to search for changes for. This method searches the properties that changed during the edit session and, if the property is contained in this array, a range object that covers the property that changed is added to *ppEnum*.

This array must be at least *cProperties* elements in size.

This parameter is ignored if *dwFlags* contains TF_GTP_INCL_TEXT and *cProperties* is zero.

### `cProperties` [in]

Specifies the number of elements in the *prgProperties* array.

This parameter can be zero if *dwFlags* contains TF_GTP_INCL_TEXT. This indicates that no property changes are obtained.

### `ppEnum` [out]

Pointer to an [IEnumTfRanges](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-ienumtfranges) interface pointer that receives the enumerator object.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |

## See also

[IEnumTfRanges](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-ienumtfranges)

[ITfEditRecord](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfeditrecord)