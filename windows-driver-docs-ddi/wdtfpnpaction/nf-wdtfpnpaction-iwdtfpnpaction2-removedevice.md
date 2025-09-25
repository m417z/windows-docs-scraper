# IWDTFPNPAction2::RemoveDevice

## Description

Removes the device.

## Parameters

### `pbSuccess` [out, retval]

True if the operation succeeds; otherwise, false.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Under the covers, this will call DIF_REMOVE.

## See also

[IWDTFPNPAction2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtfpnpaction/nn-wdtfpnpaction-iwdtfpnpaction2)