# IddCxAdapterInitAsync function

## Description

**IddCxAdapterInitAsync** is an asynchronous initiation function called by the indirect display driver (IDD) to create a WDDM graphics adapter.

## Parameters

### `pInArgs` [in]

Pointer to an [**IDARG_IN_ADAPTER_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_adapter_init) structure containing the information needed to initialize an adapter that will be hosted on a WDF device.

### `pOutArgs` [out]

Pointer to an [**IDARG_OUT_ADAPTER_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_adapter_init) structure in which the IDD returns information about the initialized adapter.

## Return value

(NTSTATUS) The method returns S_OK if the operation succeeds. Otherwise, it returns an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## See also

[**IDARG_IN_ADAPTER_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_adapter_init)

[**IDARG_OUT_ADAPTER_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_adapter_init)