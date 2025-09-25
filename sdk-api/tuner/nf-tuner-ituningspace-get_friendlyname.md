# ITuningSpace::get_FriendlyName

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_FriendlyName** method retrieves the localized, user-friendly name of the tuning space.

## Parameters

### `Name` [out]

Pointer to a variable receives the user-friendly name.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## Remarks

The caller must release the returned **BSTR** by calling **SysFreeString**.

## See also

[ITuningSpace Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituningspace)