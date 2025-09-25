# IFillLockBytes::Terminate

## Description

The **Terminate** method informs the byte array that the download has been terminated, either successfully or unsuccessfully.

## Parameters

### `bCanceled` [in]

Download is complete. If **TRUE**, the download was terminated unsuccessfully. If **FALSE**, the download terminated successfully.

## Return value

This function supports the standard return values E_OUTOFMEMORY, E_UNEXPECTED, E_INVALIDARG, and E_FAIL.

## Remarks

After this method has been called, the byte array will no longer return E_PENDING.