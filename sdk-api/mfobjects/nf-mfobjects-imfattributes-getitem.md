# IMFAttributes::GetItem

## Description

Retrieves the value associated with a key.

## Parameters

### `guidKey` [in]

A GUID that identifies which value to retrieve.

### `pValue` [in, out]

A pointer to a **PROPVARIANT** that receives the value. The method fills the **PROPVARIANT** with a copy of the stored value, if the value is found. Call **PropVariantClear** to free the memory allocated by this method. This parameter can be **NULL**. If this parameter is **NULL**, the method searches for the key and returns S_OK if the key is found, but does not copy the value.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_ATTRIBUTENOTFOUND** | The specified key was not found. |

## Remarks

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

#### Examples

The following example copies an attribute from one attribute store to another.

```cpp
HRESULT CopyAttribute(IMFAttributes *pFrom, IMFAttributes *pTo, REFGUID guidKey)
{
    PROPVARIANT val;

    HRESULT hr = pFrom->GetItem(guidKey, &val);

    if (SUCCEEDED(hr))
    {
        hr = pTo->SetItem(guidKey, val);
        PropVariantClear(&val);
    }
    else if (hr == MF_E_ATTRIBUTENOTFOUND)
    {
        hr = S_OK;
    }
    return hr;
}

```

## See also

[Attributes and Properties](https://learn.microsoft.com/windows/desktop/medfound/attributes-and-properties)

[IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes)