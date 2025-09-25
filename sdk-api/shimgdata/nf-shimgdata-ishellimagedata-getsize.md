# IShellImageData::GetSize

## Description

Gets the dimensions of the image file.

## Parameters

### `pSize` [out]

Type: **[SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size)***

A pointer to a [SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size) structure containing the size of the image. This value is valid only when the method returns **S_OK**.

## Return value

Type: **HRESULT**

Returns **S_OK** if successful or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **E_FAIL** | The image has not been decoded or the decoding process failed. |