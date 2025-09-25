# IMFCollection::AddElement

## Description

Adds an object to the collection.

## Parameters

### `pUnkElement` [in]

Pointer to the object's **IUnknown** interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If *pUnkElement* is **NULL**, a **NULL** pointer is added to the collection.

## See also

[IMFCollection](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfcollection)