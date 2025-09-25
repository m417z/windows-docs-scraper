# ITfCreatePropertyStore::CreatePropertyStore

## Description

Creates a property store object from serialized property store data.

## Parameters

### `guidProp` [in]

Contains the type identifier of the property. For more information, see [ITfPropertyStore::GetType](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfpropertystore-gettype).

### `pRange` [in]

Pointer to an [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) object that contains the text to be covered by the property store.

### `cb` [in]

Contains the size, in bytes, of the property store data contained in *pStream*.

### `pStream` [in]

Pointer to an **IStream** object that contains the property store data.

### `ppStore` [out]

Pointer to an [ITfPropertyStore](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfpropertystore) interface pointer that receives the property store object created by this method.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## See also

[ITfCreatePropertyStore interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcreatepropertystore), [ITfPropertyStore interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfpropertystore), [ITfPropertyStore::GetType](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfpropertystore-gettype), [ITfRange interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfrange)