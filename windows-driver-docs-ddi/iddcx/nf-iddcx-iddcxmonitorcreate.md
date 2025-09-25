# IddCxMonitorCreate function

## Description

An indirect display driver (IDD) calls **IddCxMonitorCreate** to create a monitor object that can later be used for arrival.

## Parameters

### `AdapterObject` [in]

The [IDDCX_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-objects) object that is hosting the newly arrived monitor.

### `pInArgs` [in]

Pointer to an [**IDARG_IN_MONITORCREATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_monitorcreate) structure containing information about the monitor.

### `pOutArgs` [out]

Pointer to an [**IDARG_OUT_MONITORCREATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_monitorcreate) structure in which the [IDDCX_MONITOR](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-objects) object is returned.

## Return value

(NTSTATUS) The method returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method may return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Remarks

An IDD must call [**IddCxMonitorArrival**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorarrival) to complete the monitor arrival.

## See also

[**IDARG_IN_MONITORCREATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_monitorcreate)

[**IDARG_OUT_MONITORCREATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_monitorcreate)

[**IddCxMonitorArrival**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorarrival)