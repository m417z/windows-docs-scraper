# ITuningSpace::put_UniqueName

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_UniqueName** method sets a unique name for the tuning space.

## Parameters

### `Name` [in]

Variable of type **BSTR** that specifies the unique name.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## Remarks

If you attempt to add a new tuning space to the System Tuning Spaces collection, this property must be unique within the collection. For more information, see [ITuningSpaceContainer::Add](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ituningspacecontainer-add).

## See also

[ITuningSpace Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituningspace)