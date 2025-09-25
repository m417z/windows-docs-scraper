# IMFDeviceTransform::GetInputStreamAttributes

## Description

The **GetInputStreamAttributes** method gets the attribute store for an input stream on this Media Foundation transform (MFT).

## Parameters

### `dwInputStreamID` [in]

Stream ID of the input stream whose state needs to be retrieved.

### `ppAttributes` [out]

Receives a pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include but not limited to values given in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Transitioning the stream state succeeded. |
| **MF_E_INVALIDREQUEST** | Device MFT could not support the request at this time. |
| **MF_E_INVALIDSTREAMNUMBER** | The stream ID is not valid. |

## Remarks

This method is used by DTM to get a specific input stream’s attribute store.

## See also

[IMFDeviceTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imfdevicetransform)