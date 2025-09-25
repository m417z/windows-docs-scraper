# IMPEG2_TIF_CONTROL::AddPIDs

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **AddPIDs** method tells the Network Provider which PIDs the TIF should receive.

## Parameters

### `ulcPIDs` [in]

Specifies the number of PIDs to add. This value must be equal to the number of elements in the array specified by *pulPIDs*.

### `pulPIDs` [in]

Specifies an array of PID values to add. The array must contain *ulcPIDs* elements.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Only the TIF knows which table sections it requires. It uses this method to tell the Network Provider the PIDs for the packets that contain those tables. The Network Provider forwards the information to the Demux, which immediately begins routing packets with the specified PIDs to the TIF.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMPEG2_TIF_CONTROL Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nn-bdatif-impeg2_tif_control)

[IMPEG2_TIF_CONTROL::GetPIDs](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nf-bdatif-impeg2_tif_control-getpids)