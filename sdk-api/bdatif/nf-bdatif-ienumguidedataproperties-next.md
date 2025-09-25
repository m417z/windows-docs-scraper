# IEnumGuideDataProperties::Next

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **Next** method retrieves the specified number of items in the enumeration sequence.

## Parameters

### `celt` [in]

Specifies the number of items to retrieve.

### `ppprop` [out]

Address of an array of size *celt*, allocated by the caller. The array is filled with [IGuideDataProperty](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nn-bdatif-iguidedataproperty) interface pointers.

### `pcelt` [out]

Receives the number of items received.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | The collection is at the end of the enumeration sequence. |
| **E_POINTER** | NULL pointer argument. |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IEnumGuideDataProperties Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nn-bdatif-ienumguidedataproperties)