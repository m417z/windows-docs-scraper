## Description

The **IWiaMiniDrv::drvUnInitializeWia** method releases resources held by the minidriver.

## Parameters

### `__MIDL__IWiaMiniDrv0064`

*pWiasContext* [in]

Pointer to a WIA item context.

## Return value

On success, the method should return **S_OK** If the method fails, it should return a standard COM error code.

## Remarks

The WIA service calls the **IWiaMiniDrv::drvUnInitializeWia** method when the resources associated with an application item tree are no longer needed. The minidriver can then unload any DLLs and free any allocated memory.

## See also

[IWiaMiniDrv](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nn-wiamindr_lh-iwiaminidrv)

[IWiaMiniDrv::drvInitializeWia](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvinitializewia)