# IWDTFPNPActions2::RestartDevice

## Description

Initiates a device restart.

## Parameters

### `pbSuccess` [out, retval]

True if the operation succeeds; otherwise, false.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

From a SetupDi interface perspective, this will translate to a DICS_PROPCHANGE.
See the MSDN docs for details.