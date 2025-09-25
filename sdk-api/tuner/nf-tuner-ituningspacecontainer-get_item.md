# ITuningSpaceContainer::get_Item

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_Item** method retrieves a tuning space with the specified ID.

## Parameters

### `varIndex` [in]

**VARIANT** that specifies the ID of the tuning space.

### `TuningSpace` [out]

Address of an [ITuningSpace](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituningspace) interface pointer that will be set to the returned interface.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## Remarks

Tuning spaces are identified by ID number. The ID number is unique within the collection. The range of valid IDs is not guaranteed to be contiguous; there may be holes if tuning spaces are added and then removed.

#### Examples

```cpp

CComPtr <ITuningSpaceContainer>  pTuningSpaceContainer;
// Create the SystemTuningSpaces object (not shown).

long cCount = 0;
long ID = 1; // zero is not a valid ID.
hr = pTuningSpaceContainer->get_Count(&cCount);
if (SUCCEEDED(hr))
{
    while (cCount)
    {
        CComPtr<ITuningSpace> pTuningSpace;
        CComVariant varIndex(ID);
        hr = pITuningSpaceContainer->get_Item(varIndex, &pTuningSpace);
        if (SUCCEEDED(hr))
        {
             // pTuningSpace now points to the tuning space with this ID.
             --cCount;
        }
        ID++; // increment for the next ID.
    }
}

```

## See also

[ITuningSpaceContainer Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituningspacecontainer)