# ITuningSpace::get__NetworkType

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_NetworkType** method retrieves the network type for this tuning space.

## Parameters

### `NetworkTypeGuid` [out]

Pointer to a variable that receives the network type GUID. This GUID corresponds to the CLSID of the Network Provider for the tuning space. For some tuning spaces, the network type is GUID_NULL, which means the tuning space does not use a Network Provider filter.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## See also

[ITuningSpace Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituningspace)