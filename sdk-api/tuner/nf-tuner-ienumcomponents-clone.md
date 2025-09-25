# IEnumComponents::Clone

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **Clone** method creates a new copy of the entire collection.

## Parameters

### `ppEnum` [out]

Address of an **IEnumComponents** interface pointer that will be set to the new collection.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## Remarks

The application must release this new collection when done with it.

## See also

[IEnumComponents Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ienumcomponents)