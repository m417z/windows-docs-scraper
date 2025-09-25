# IMFDeviceTransform::GetOutputStreamAttributes

## Description

The **GetOutputStreamAttributes** method gets the attribute store for an output stream on this Media Foundation transform (MFT).

## Parameters

### `dwOutputStreamID`

The Stream ID of the output stream whose state needs to be retrieved.

### `ppAttributes`

Receives a pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include but not limited to values given in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Initialization succeeded. |
| **MF_E_INVALIDREQUEST** | Device MFT could not support the request at this time. |
| **MF_E_INVALIDSTREAMNUMBER** | Returned when an invalid stream ID is passed. |

## Remarks

This function is used by the DTM to get a specific output stream’s attribute store.

## See also

[IMFDeviceTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imfdevicetransform)