# IMFAttributes::CopyAllItems

## Description

Copies all of the attributes from this object into another attribute store.

## Parameters

### `pDest` [in]

A pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface of the attribute store that receives the copy.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method deletes all of the attributes originally stored in *pDest*.

**Note**

When you call **CopyAllItems** on an [IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample), which inherits this method, the sample time, duration, and flags are not copied to the destination sample. You must copy these values to the new sample manually.

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

#### Examples

To copy a single attribute rather than all of the attributes, you can use the following code:

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