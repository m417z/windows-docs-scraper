# IWDTFPNPAction2::RescanParentDevice

## Description

Rescans and re-enumerates the target device's parent device.

## Parameters

### `pbSuccess` [out, retval]

True if the operation succeeds; otherwise, false.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

In essence, **RescanParentDevice** calls
**CM_Reenumerate_DevNode()**. See the MSDN documentation for
**CM_Reenumerate_DevNode()**.

## See also

[IWDTFPNPAction2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtfpnpaction/nn-wdtfpnpaction-iwdtfpnpaction2)