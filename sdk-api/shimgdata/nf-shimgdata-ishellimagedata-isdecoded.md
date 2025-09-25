# IShellImageData::IsDecoded

## Description

Determines whether the image has been decoded by calling [IShellImageData::Decode](https://learn.microsoft.com/windows/desktop/api/shimgdata/nf-shimgdata-ishellimagedata-decode). Many operations return a failure code if the image is not first decoded.

## Return value

Type: **HRESULT**

Returns one of the following:

| Return code | Description |
| --- | --- |
| **S_OK** | [IShellImageData::Decode](https://learn.microsoft.com/windows/desktop/api/shimgdata/nf-shimgdata-ishellimagedata-decode) was called on the image and was successful. |
| **S_FALSE** | All other cases. |