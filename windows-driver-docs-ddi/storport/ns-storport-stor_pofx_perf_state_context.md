## Description

**STOR_POFX_PERF_STATE_CONTEXT** is the structure pointed to by the **Parameters** parameter when a miniport's [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) routine is called with a **ControlType** of **ScsiAdapterPoFxSetPerfState**.

## Members

### `Version`

Version of this structure. Currently set to 1.

### `Size`

Size of this structure, in bytes. Set to ```sizeof(STOR_POFX_PERF_STATE_CONTEXT)```.

### `ComponentIndex`

The index of the associated component.

### `Succeeded`

BOOLEAN value. If the platform extension plug-in (PEP) has no part in the P-State transition (that is, only the miniport initiates the corresponding physical power state transition), then this field should always be TRUE. If the PEP plays some part in the P-State transition then this field indicates whether the PEP was successful (TRUE on success; FALSE otherwise).

### `Context`

Pointer to the same context that was passed in a call to [**StorPortPoFxSetPerfState**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportpofxsetperfstate). This is typically the P-state index.

## See also

[**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control)

[**StorPortPoFxSetPerfState**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportpofxsetperfstate)