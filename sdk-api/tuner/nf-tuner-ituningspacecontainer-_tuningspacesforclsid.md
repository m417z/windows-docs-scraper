# ITuningSpaceContainer::_TuningSpacesForCLSID

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **_TuningSpacesForCLSID** method retrieves a collection of tuning spaces that match the specified CLSID.

## Parameters

### `SpaceCLSID` [in]

Specifies the CLSID of the tuning spaces to retrieve.

### `NewColl` [out]

Address of a variable that receives an [ITuningSpaces](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituningspaces) interface pointer. The caller must release the interface.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## Remarks

The CLSID represents the object that implements the tuning space. The same object may implement several related tuning spaces. For example, ATSC Digital Antenna and ATSC Digital Cable are both supported by the [ATSCTuningSpace](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/atsctuningspace-object) object (CLSID_ATSCTuningSpace).

This method matches against the CLSID returned by the [ITuningSpace::get_CLSID](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ituningspace-get_clsid) method. The returned collection might be empty; call [ITuningSpaces::get_Count](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ituningspaces-get_count) to determine how many tuning spaces were returned.

## See also

[ITuningSpaceContainer Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituningspacecontainer)