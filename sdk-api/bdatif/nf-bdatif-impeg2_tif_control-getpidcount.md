# IMPEG2_TIF_CONTROL::GetPIDCount

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetPIDCount** method retrieves the number of MPEG-2 Packet IDs being filtered by the [MPEG-2 Demultiplexer](https://learn.microsoft.com/windows/desktop/DirectShow/mpeg-2-demultiplexer) into the TIF's input data.

## Parameters

### `pulcPIDs` [out]

Pointer to a variable that receives the number of PIDs currently being filtered to the Demux.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

A custom TIF extension might or might not need this method.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMPEG2_TIF_CONTROL Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nn-bdatif-impeg2_tif_control)

[IMPEG2_TIF_CONTROL::GetPIDs](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nf-bdatif-impeg2_tif_control-getpids)