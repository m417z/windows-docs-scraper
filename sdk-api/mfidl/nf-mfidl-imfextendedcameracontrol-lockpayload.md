## Description

Locks the internal payload buffer contained in the capture device control to enable querying or changing the payload.

## Parameters

### `ppPayload`

Receives a BYTE pointer to the buffer containing the raw payload. The caller should not free the buffer directly, but instead should call [IMFExtendedCameraControl::UnlockPayload](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfextendedcameracontrol-unlockpayload) to free the resources.

### `pulPayload`

Receives the size of the buffer returned in *ppPayload*.

## Return value

On success, returns S_OK.

## Remarks

## See also