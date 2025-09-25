# ITfCreatePropertyStore::IsStoreSerializable

## Description

Determines if a property store can be stored as persistent data.

## Parameters

### `guidProp` [in]

Contains the type identifier of the property. For more information, see [ITfPropertyStore::GetType](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfpropertystore-gettype).

### `pRange` [in]

Pointer to an [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) object that contains the text covered by the property store.

### `pPropStore` [in]

Pointer to the [ITfPropertyStore](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfpropertystore) object.

### `pfSerializable` [out]

Pointer to a **BOOL** that receives a flag that indicates if the property store can be serialized. Receives nonzero if the property store can be serialized or zero otherwise.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## See also

[ITfCreatePropertyStore interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcreatepropertystore), [ITfPropertyStore interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfpropertystore), [ITfPropertyStore::GetType](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfpropertystore-gettype), [ITfRange interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfrange)