# IMFAttributes::GetString

## Description

Retrieves a wide-character string associated with a key.

## Parameters

### `guidKey` [in]

GUID that identifies which value to retrieve. The attribute type must be **MF_ATTRIBUTE_STRING**.

### `pwszValue` [out]

Pointer to a wide-character array allocated by the caller. The array must be large enough to hold the string, including the terminating **NULL** character. If the key is found and the value is a string type, the method copies the string into this buffer. To find the length of the string, call [IMFAttributes::GetStringLength](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfattributes-getstringlength).

### `cchBufSize` [in]

The size of the *pwszValue* array, in characters. This value includes the terminating NULL character.

### `pcchLength` [out]

Receives the number of characters in the string, excluding the terminating **NULL** character. This parameter can be **NULL**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_OUTOFMEMORY** | The length of the string is too large to fit in a **UINT32** value. |
| **E_NOT_SUFFICIENT_BUFFER** | The buffer is not large enough to hold the string. |
| **MF_E_ATTRIBUTENOTFOUND** | The specified key was not found. |
| **MF_E_INVALIDTYPE** | The attribute value is not a string. |

## Remarks

You can also use the [IMFAttributes::GetAllocatedString](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfattributes-getallocatedstring) method, which allocates the buffer to hold the string.

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

#### Examples

The following code example shows how to get an attribute whose value is a string.

```
HRESULT AttributeGetString(IMFAttributes *pAttributes)
{
    HRESULT hr = S_OK;
    UINT32 cchLength = 0;
    WCHAR *pString = NULL;

    hr = pAttributes->GetStringLength(MY_ATTRIBUTE, &cchLength);

    if (SUCCEEDED(hr))
    {
        pString = new WCHAR[cchLength + 1];
        if (pString == NULL)
        {
            hr = E_OUTOFMEMORY;
        }
    }

    if (SUCCEEDED(hr))
    {
        hr = pAttributes->GetString(
            MY_ATTRIBUTE, pString, cchLength + 1, &cchLength);
    }

    if (pString)
    {
        delete [] pString;
    }
    return hr;
}
```

## See also

[Attributes and Properties](https://learn.microsoft.com/windows/desktop/medfound/attributes-and-properties)

[IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes)

[MF_ATTRIBUTE_TYPE](https://learn.microsoft.com/windows/desktop/api/mfobjects/ne-mfobjects-mf_attribute_type)