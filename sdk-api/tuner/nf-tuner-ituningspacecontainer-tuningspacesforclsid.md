# ITuningSpaceContainer::TuningSpacesForCLSID

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **TuningSpacesForCLSID** method retrieves a collection of tuning spaces that match the specified CLSID.

This method is intended for Automation clients, because it returns the CLSID as a **BSTR**. C++ applications can use the [ITuningSpaceContainer::_TuningSpacesForCLSID](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ituningspacecontainer-tuningspacesforclsid) method instead, which returns a GUID value.

## Parameters

### `SpaceCLSID` [in]

String representation of the CLSID of the tuning space.

### `NewColl` [out]

Receives a pointer to the [ITuningSpaces](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituningspaces) interface. The caller must release the interface.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## See also

[ITuningSpaceContainer Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituningspacecontainer)