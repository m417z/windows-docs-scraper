# IEnumTuneRequests::Next

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **Next** method retrieves the specified number of items in the collection.

## Parameters

### `celt` [in]

Specifies the number of items to retrieve.

### `ppprop` [out]

Array of size *celt* that is filled with [ITuneRequest](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-itunerequest) interface pointers.

### `pcelt` [out]

Receives the number of items retrieved.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | The collection is at the end of the enumeration sequence. |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IEnumTuneRequests Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nn-bdatif-ienumtunerequests)