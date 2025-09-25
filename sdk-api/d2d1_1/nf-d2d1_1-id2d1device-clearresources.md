# ID2D1Device::ClearResources

## Description

Clears all of the rendering resources used by Direct2D.

## Parameters

### `millisecondsSinceUse`

Type: **UINT**

Discards only resources that haven't been used for greater than the specified time in milliseconds. The default is 0 milliseconds.

## Return value

Type: **HRESULT**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ID2D1Device](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1device)