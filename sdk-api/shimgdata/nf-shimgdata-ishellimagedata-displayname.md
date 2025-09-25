# IShellImageData::DisplayName

## Description

Gets the name of the file if [IShellImageData](https://learn.microsoft.com/windows/desktop/api/shimgdata/nn-shimgdata-ishellimagedata) was initialized on a file path. Otherwise, gets the name of the data stream.

## Parameters

### `wszName` [in, out]

Type: **LPWSTR**

A pointer to a buffer containing the display name as a Unicode string. On exit, the contents of the buffer are only valid when the method returns S_OK.

### `cch` [in]

Type: **UINT**

The size, in characters, of the buffer pointed to by *wszName*.

## Return value

Type: **HRESULT**

Returns S_OK if successful or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **E_FAIL** | The file name or stream name cannot be retrieved. |