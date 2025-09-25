# ITuningSpace::get_CLSID

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_CLSID** method gets the CLSID of the tuning space as a **BSTR**.

## Parameters

### `SpaceCLSID` [out]

Pointer to a variable that receives a string representation of the tuning space CLSID.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## Remarks

This method provides script access to the **IPersist::GetClassID** method.

The returned CLSID represents the COM object that implements this tuning space. The CLSID is not guaranteed to be unique to this tuning space, however, because the same object may implement several tuning spaces.

## See also

[ITuningSpace Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituningspace)