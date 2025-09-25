# IMSVidCtl::get_FeaturesActive

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_FeaturesActive** method retrieves the features that are currently active.

## Parameters

### `pVal` [out]

Receives an [IMSVidFeatures](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidfeatures) interface pointer. The caller must release the interface.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

If no features are active, the method might return **NULL** in the *pVal* parameter. Otherwise, it returns a collection of feature objects. Use the returned [IMSVidFeatures](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidfeatures) pointer to enumerate the collection.

#### Examples

```cpp

CComPtr<IMSVidFeatures> pFeatures;
hr = m_pVideoControl->get_FeaturesActive(&pFeatures);
if (SUCCEEDED(hr) && pFeatures)
{
    long c;
    pFs->get_Count(&c);
    /* Enumerate the features */
}

```

## See also

[Displaying Closed Captioning in C++](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/displaying-closed-captioning-in-c)

[IMSVidCtl Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidctl)

[IMSVidCtl::put_FeaturesActive](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-put_featuresactive)