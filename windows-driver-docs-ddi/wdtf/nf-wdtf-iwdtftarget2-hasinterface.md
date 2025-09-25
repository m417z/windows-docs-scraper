# IWDTFTarget2::HasInterface

## Description

Determines whether the target supports a given interface.

## Parameters

### `WDTFInterfaceName`

### `Args`

### `MonikerSuffix` [in, optional]

An optional moniker that defines more options about how the interface should be instantiated.

This parameter is not yet implemented. Set *MonikerSuffix* to a **VARIANT** that
contains **VT_EMPTY**.

### `pResult` [out, retval]

True if the target supports the interface; otherwise false.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWDTFTarget2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtf/nn-wdtf-iwdtftarget2)