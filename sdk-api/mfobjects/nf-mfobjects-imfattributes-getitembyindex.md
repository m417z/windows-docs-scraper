# IMFAttributes::GetItemByIndex

## Description

Retrieves an attribute at the specified index.

## Parameters

### `unIndex` [in]

Index of the attribute to retrieve. To get the number of attributes, call [IMFAttributes::GetCount](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfattributes-getcount).

### `pguidKey` [out]

Receives the GUID that identifies this attribute.

### `pValue` [in, out]

Pointer to a **PROPVARIANT** that receives the value. This parameter can be **NULL**. If it is not **NULL**, the method fills the **PROPVARIANT** with a copy of the attribute value. Call **PropVariantClear** to free the memory allocated by this method.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | Invalid index. |

## Remarks

To enumerate all of an object's attributes in a thread-safe way, do the following:

1. Call [IMFAttributes::LockStore](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfattributes-lockstore) to prevent another thread from adding or deleting attributes.
2. Call [IMFAttributes::GetCount](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfattributes-getcount) to find the number of attributes.
3. Call **GetItemByIndex** to get each attribute by index.
4. Call [IMFAttributes::UnlockStore](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfattributes-unlockstore) to unlock the attribute store.

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[Attributes and Properties](https://learn.microsoft.com/windows/desktop/medfound/attributes-and-properties)

[IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes)