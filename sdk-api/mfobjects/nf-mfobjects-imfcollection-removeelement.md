# IMFCollection::RemoveElement

## Description

Removes an object from the collection.

## Parameters

### `dwElementIndex` [in]

Zero-based index of the object to remove. Objects are indexed in the order in which they were added to the collection.

### `ppUnkElement` [out]

Receives a pointer to the **IUnknown** interface of the object. The caller must release the interface. This parameter cannot be **NULL**, but the retrieved pointer value might be **NULL**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFCollection](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfcollection)