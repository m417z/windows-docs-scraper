# IMFSystemId::Setup

## Description

Sets up the [IMFSystemId](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsystemid).

## Parameters

### `stage`

Stage in the setup process. 0 or 1.

### `cbIn`

Size of the input buffer.

### `pbIn`

The input buffer.

### `pcbOut`

Size of output buffer.

### `ppbOut`

The output buffer.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFSystemId](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsystemid)