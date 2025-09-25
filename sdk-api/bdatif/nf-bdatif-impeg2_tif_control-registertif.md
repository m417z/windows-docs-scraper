# IMPEG2_TIF_CONTROL::RegisterTIF

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **RegisterTIF** method is called by the Transport Information Filter (TIF) to register itself with the Network Provider.

## Parameters

### `pUnkTIF` [in]

Pointer to the TIF's **IUnknown** interface.

### `ppvRegistrationContext` [in, out]

Pointer to a variable that receives an identifier. Use this value as the parameter to the [IMPEG2_TIF_CONTROL::UnregisterTIF](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nf-bdatif-impeg2_tif_control-unregistertif) method.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | Invalid argument. |
| **E_NOINTERFACE** | Could not find a necessary interface on the TIF. |
| **VFW_E_ALREADY_CONNECTED** | A TIF is already registered with the Network Provider. |

## Remarks

Call this method immediately after the TIF's input pin is connected to the Demux.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMPEG2_TIF_CONTROL Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nn-bdatif-impeg2_tif_control)