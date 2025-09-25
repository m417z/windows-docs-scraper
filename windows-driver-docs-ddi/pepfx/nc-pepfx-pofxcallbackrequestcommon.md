# POFXCALLBACKREQUESTCOMMON callback function (pepfx.h)

## Description

The **RequestCommon** routine is a generic request handler.

## Parameters

### `RequestId` [in]

A request ID that specifies the operation being requested.

### `Data` [in, out, optional]

A pointer to a data structure that contains the input data and/or result data for the request specified by the *RequestId* parameter.

## Return value

**RequestCommon** returns STATUS_SUCCESS if the request is successfully handled. Otherwise, it returns an appropriate error status code.

## Remarks

This routine is implemented by the [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx) and is called by the platform extension plug-in (PEP). The **RequestCommon** member of the [PEP_KERNEL_INFORMATION_STRUCT_V3](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_kernel_information_struct_v3) structure is a pointer to a **RequestCommon** routine.

A PEP can call this routine at IRQL <= HIGH_LEVEL.

## See also

[PEP_KERNEL_INFORMATION_STRUCT_V3](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_kernel_information_struct_v3)