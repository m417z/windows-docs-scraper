# IShellImageData::GetRawDataFormat

## Description

Retrieves a GUID that identifies the format of the image.

## Parameters

### `pDataFormat` [out]

Type: **GUID***

A pointer to a value indicating the format. This value is valid only when the method returns S_OK.

## Return value

Type: **HRESULT**

Returns S_OK if successful or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **E_FAIL** | The image has not been decoded or the decoding process failed. |

## Remarks

GUIDs that identify various file formats are defined in Gdiplusimaging.h.