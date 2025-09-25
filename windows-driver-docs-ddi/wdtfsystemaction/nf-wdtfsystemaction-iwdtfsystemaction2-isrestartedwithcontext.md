# IWDTFSystemAction2::IsRestartedWithContext

## Description

Gets a value that indicates whether the test script was restarted for a specific context.

## Parameters

### `psContextName` [in]

The context name.

### `pbIsRestarted` [out, retval]

True if the script was restarted with the context; otherwise, false.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWDTFSystemAction2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtfsystemaction/nn-wdtfsystemaction-iwdtfsystemaction2)