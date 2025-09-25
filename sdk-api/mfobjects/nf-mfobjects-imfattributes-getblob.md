# IMFAttributes::GetBlob

## Description

Retrieves a byte array associated with a key. This method copies the array into a caller-allocated buffer.

## Parameters

### `guidKey` [in]

GUID that identifies which value to retrieve. The attribute type must be **MF_ATTRIBUTE_BLOB**.

### `pBuf` [out]

Pointer to a buffer allocated by the caller. If the key is found and the value is a byte array, the method copies the array into this buffer. To find the required size of the buffer, call [IMFAttributes::GetBlobSize](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfattributes-getblobsize).

### `cbBufSize` [in]

The size of the *pBuf* buffer, in bytes.

### `pcbBlobSize` [out]

Receives the size of the byte array. This parameter can be **NULL**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| ****S_OK**** | The method succeeded. |
| ****E_NOT_SUFFICIENT_BUFFER**** | The buffer is not large enough to the array. |
| ****MF_E_ATTRIBUTENOTFOUND**** | The specified key was not found. |
| ****MF_E_INVALIDTYPE**** | The attribute value is not a byte array. |

## Remarks

You can also use the [IMFAttributes::GetAllocatedBlob](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfattributes-getallocatedblob) method, which allocates the buffer to hold the byte array.

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

#### Examples

The following code example shows how to get an attribute whose value is a byte array.

```
HRESULT AttributeGetBlob(IMFAttributes *pAttributes)
{
    HRESULT hr = S_OK;
    UINT32 cbBlob = 0;
    BYTE *pBlob = NULL;

    hr = pAttributes->GetBlobSize(MY_ATTRIBUTE, &cbBlob);

    if (SUCCEEDED(hr))
    {
        pBlob = new BYTE[cbBlob];
        if (pBlob == NULL)
        {
            hr = E_OUTOFMEMORY;
        }
    }

    if (SUCCEEDED(hr))
    {
        hr = pAttributes->GetBlob(MY_ATTRIBUTE, pBlob, cbBlob, &cbBlob);
    }

    if (pBlob)
    {
        delete [] pBlob;
    }
    return hr;
}
```

## See also

[Attributes and Properties](https://learn.microsoft.com/windows/desktop/medfound/attributes-and-properties)

[IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes)

[MF_ATTRIBUTE_TYPE](https://learn.microsoft.com/windows/desktop/api/mfobjects/ne-mfobjects-mf_attribute_type)