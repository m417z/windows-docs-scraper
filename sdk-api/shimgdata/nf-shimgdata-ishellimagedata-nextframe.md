# IShellImageData::NextFrame

## Description

Switches to the next frame of an animated image.

## Return value

Type: **HRESULT**

Returns S_OK if successful or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **E_FAIL** | The current frame cannot be retrieved. |
| **S_FALSE** | The image is not animated, the image has not yet been decoded, or a limit on the number of times to loop the animation has been reached. |
| **E_PENDING** | The next frame is not yet available. |
| **E_NOMOREDATA** | No further data is available. |