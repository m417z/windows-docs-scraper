# ITuningSpaceContainer::TuningSpacesForName

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **TuningSpacesForName** method retrieves a collection of tuning spaces that match the specified name.

## Parameters

### `Name` [in]

String that contains a regular expression to match against either the friendly name or the unique name of the tuning space.

### `NewColl` [out]

Address of variable that receives an [ITuningSpaces](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituningspaces) interface pointer. Use this interface to enumerate the collection. The caller must release the interface.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## Remarks

The returned collection might be empty, if no tuning spaces match the name.

#### Examples

```cpp

CComPtr <ITuningSpaceContainer>  pTuningSpaceContainer;
// Create the SystemTuningSpaces object (not shown).

// Try to match any tuning spaces named "Local (something) Cable".
CComPtr<ITuningSpaces> pTunes;
CComBSTR bstrName("Local.*Cable");
hr = pITuningSpaceContainer->TuningSpacesForName(bstrName, &pTunes);
if (SUCCEEDED(hr))
{
    // Find the size of the returned collection.
    long cCount = 0;
    hr = pTunes->get_Count(&cCount);
    if (SUCCEEDED(hr) && (cCount > 0))
    {
        // Enumerate the collection.
        CComPtr<IEnumTuningSpaces> pTuneEnum;
        hr = pTunes->get_EnumTuningSpaces(&pTuneEnum);
        if (SUCCEEDED(hr))
        {
            // Use IEnumTuningSpaces to iterate through the collection.
        }
    }
}

```

## See also

[ITuningSpaceContainer Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituningspacecontainer)