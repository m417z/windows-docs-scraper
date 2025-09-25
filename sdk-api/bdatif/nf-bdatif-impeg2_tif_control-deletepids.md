# IMPEG2_TIF_CONTROL::DeletePIDs

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **DeletePIDs** method informs the Network Provider that the TIF no longer requires the specified PID.

## Parameters

### `ulcPIDs` [in]

Specifies the number of PIDs to delete. This value must equal the number of elements in the array specified by *pulPIDs*.

### `pulPIDs` [in]

Specifies an array of PID values containing *ulcPIDs* elements.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method is called if a set of tables in the transport stream goes away, in order to remove the PSI/SI MPEG2 packet IDs from the TIF's data stream.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMPEG2_TIF_CONTROL Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nn-bdatif-impeg2_tif_control)