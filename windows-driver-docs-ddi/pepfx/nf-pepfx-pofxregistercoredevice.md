# PoFxRegisterCoreDevice function (pepfx.h)

## Description

The **PoFxRegisterCoreDevice** routine registers a new core system resource with the Windows power management framework (PoFx).

## Parameters

### `Id` [in]

A string that uniquely identifies the core system resource. This member is a pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains a [device identification string](https://learn.microsoft.com/windows-hardware/drivers/install/device-identification-strings).

### `Device` [in]

A pointer to a [PO_FX_CORE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_po_fx_core_device) structure that describes the power characteristics of the core system resource.

### `Handle` [out]

A pointer to a location to which the routine writes a POHANDLE value. This handle represents the registration of the core system resource with PoFx.

## Return value

**PoFxRegisterCoreDevice** returns STATUS_SUCCESS if the call successfully registers the PEP. Possible error return values include the following status codes.

| Return value | Description |
| --- | --- |
| STATUS_INVALID_PARAMETER | The component count for this device is zero, or the **PO_FX_CORE_DEVICE** structure contains an invalid version number, or the **ComponentCriticalTransitionCallback** member of this structure contains an invalid function pointer. |
| STATUS_INSUFFICIENT_RESOURCES | Unable to allocate the resources required to complete the requested registration. |

## Remarks

This routine registers a core system resource so that this resource can be power-managed by PoFx.

Core system resources are hardware devices, such as timers and interrupt controllers, that are managed by the Windows hardware abstraction layer (HAL). These devices provide basic functions that are required by the operating system. Due to the close relationship between core system resources and processors, the power management of these resources needs to be coordinated with processor idle state management.

The **PoFxRegisterCoreDevice** routine should be called at IRQL = PASSIVE_LEVEL.

## See also

[PO_FX_CORE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_po_fx_core_device)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)