# IWDTFPNPActions2::RequestEjectDevice

## Description

Initiates a device eject.

## Parameters

### `pbSuccess` [out, retval]

True if the operation succeeds; otherwise, false.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This will in essence call **CM_Request_Device_Eject()**.
See the MSDN documentation for details.