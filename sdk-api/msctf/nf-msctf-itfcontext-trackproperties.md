# ITfContext::TrackProperties

## Description

Obtains a special property that can enumerate multiple properties over multiple ranges.

## Parameters

### `prgProp` [in]

Contains an array of property identifiers that specify the properties to track.

### `cProp` [in]

Contains the number of property identifiers in the *prgProp* array.

### `prgAppProp` [in]

Contains an array of application property identifiers that specify the application properties to track.

### `cAppProp` [in]

Contains the number of application property identifiers in the *prgAppProp* array.

### `ppProperty` [out]

Pointer to an [ITfReadOnlyProperty](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfreadonlyproperty) interface pointer that receives the tracking property.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **TF_E_DISCONNECTED** | The context object is not on a document stack. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |

## Remarks

This method is used to quickly identify ranges with consistent property values for multiple properties. While this method could be duplicated using only the [ITfContext::GetProperty](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontext-getproperty) method, the TSF manager can accomplish this task more quickly.

The property obtained by this method is a VT_UNKNOWN type. This property can be used to obtain an [IEnumTfPropertyValue](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-ienumtfpropertyvalue) enumerator by calling the **QueryInterface** method with IID_IEnumTfPropertyValue. This enumerator contains property values specified by *prgProp* and *prgAppProp*.

#### Examples

```cpp

const GUID *rgGuids[2] = {  &GUID_PROP_COMPOSING,
                            &GUID_PROP_ATTRIBUTE };
HRESULT hr;
ITfReadOnlyProperty *pTrackProperty;
TF_SELECTION sel;
IEnumTfRanges *pEnumRanges;
ITfRange *pRangeValue;

// Get the tracking property.
hr = pContext->TrackProperties(NULL, 0, rgGuids, 2, &pTrackProperty);

// Get the selection range.
hr = pContext->GetSelection(ec, TF_DEFAULT_SELECTION, 1, &sel, &cFetched);

// Use the property from TrackProperties to get an enumeration of the ranges
// within the selection range that have the same property values.
hr = pTrackProperty->EnumRanges(ec, &pEnumRanges, sel.range);

// Enumerate the ranges of text.
while(pEnumRanges->Next(1, &pRangeValue, NULL) == S_OK)
{
    VARIANT varTrackerValue;
    TF_PROPERTYVAL tfPropertyVal;
    IEnumTfPropertyValue *pEnumPropVal;

    // Get the values for this range of text.
    hr = pTrackProperty->GetValue(ec, pRangeValue, &varTrackerValue);

    // Because pTrackProperties originates from TrackProperties,
    // varTrackerValue can be identified as a VT_UNKNOWN/IEnumTfPropertyValue.
    varTrackerValue.punkVal->QueryInterface(    IID_IEnumTfPropertyValue,
                                                (void **)&pEnumPropVal);

    while(pEnumPropVal->Next(1, &tfPropertyVal, NULL) == S_OK)
    {
        BOOL fComposingValue;
        TfGuidAtom gaDispAttrValue;

        // Is this the composition property?
        if (IsEqualGUID(tfPropertyVal.guidId, GUID_PROP_COMPOSING))
        {
            fComposingValue = (BOOL)tfPropertyVal.varValue.lVal;
        }
        // Or is this the attribute property?
        else if (IsEqualGUID(tfPropertyVal.guidId, GUID_PROP_ATTRIBUTE))
        {
            gaDispAttrValue = (TfGuidAtom)tfPropertyVal.varValue.lVal;
        }

        // Clear the property.
        VariantClear(&tfPropertyVal.varValue);
    }

    // Clear the tracker property.
    VariantClear(&varTrackerValue);

    // Release the property enumerator.
    pEnumPropVal->Release();

    // Release the range.
    pRangeValue->Release();
}

// Release the selection range.
sel.range->Release();

```

## See also

[IEnumTfPropertyValue](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-ienumtfpropertyvalue)

[ITfContext](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontext)

[ITfContext::GetProperty](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontext-getproperty)

[ITfReadOnlyProperty](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfreadonlyproperty)