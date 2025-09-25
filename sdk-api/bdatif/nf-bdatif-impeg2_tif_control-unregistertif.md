# IMPEG2_TIF_CONTROL::UnregisterTIF

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **UnregisterTIF** method unregisters the TIF with the Network Provider.

## Parameters

### `pvRegistrationContext` [in]

Identifier returned by the [IMPEG2_TIF_CONTROL::RegisterTIF](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nf-bdatif-impeg2_tif_control-registertif) method.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | Invalid argument. |

## Remarks

Call this method after the TIF's input pin has been disconnected from the Demux.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMPEG2_TIF_CONTROL Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nn-bdatif-impeg2_tif_control)