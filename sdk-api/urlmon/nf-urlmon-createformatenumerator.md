# CreateFormatEnumerator function

## Description

Creates an object that implements [IEnumFORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumformatetc) over a static array of [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structures.

## Parameters

### `cfmtetc` [in]

Number of [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structures in the static array specified by the *rgfmtetc* parameter. The *cfmtetc* parameter cannot be zero.

### `rgfmtetc` [in]

Pointer to a static array of [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structures.

### `ppenumfmtetc` [out]

Address of [IEnumFORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumformatetc) pointer variable that receives the interface pointer to the enumerator object.

## Return value

This function returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more parameters are invalid. |

## Remarks

The **CreateFormatEnumerator** function creates an enumerator object that implements [IEnumFORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumformatetc) over a static array of [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structures. The *cfmtetc* parameter specifies the number of these structures. With the pointer, you can call the standard enumeration methods to enumerate the structures.