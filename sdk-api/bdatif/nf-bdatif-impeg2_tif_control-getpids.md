# IMPEG2_TIF_CONTROL::GetPIDs

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetPIDs** method retrieves the list of MPEG-2 Packet IDs being filtered into the TIF's input data.

## Parameters

### `pulcPIDs` [out]

Pointer to a variable that receives the number of PIDs that were retrieved.

### `pulPIDs` [out]

Pointer to a variable that receives an array of returned **ULONG** values representing the PID values. The number of elements in the array is equal to the value of *pulcPIDs*.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

A custom TIF extension might or might not have need for this method.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMPEG2_TIF_CONTROL Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nn-bdatif-impeg2_tif_control)

[IMPEG2_TIF_CONTROL::AddPIDs](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nf-bdatif-impeg2_tif_control-addpids)

[IMPEG2_TIF_CONTROL::GetPIDCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nf-bdatif-impeg2_tif_control-getpidcount)