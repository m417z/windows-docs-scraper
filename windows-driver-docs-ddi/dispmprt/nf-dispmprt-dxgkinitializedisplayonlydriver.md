# DxgkInitializeDisplayOnlyDriver function

## Description

Loads and initializes the DirectX graphics kernel subsystem (Dxgkrnl.sys) for use by a kernel mode display-only driver (KMDOD).

## Parameters

### `DriverObject` [in]

A pointer to a [DRIVER_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object) structure. The KMDOD previously obtained this pointer in its [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) function.

### `RegistryPath` [in]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that supplies the path to the KMDOD's service registry key. The KMDOD previously obtained this pointer in its [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) function.

### `KmdDodInitializationData` [in]

A pointer to a [KMDDOD_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_kmddod_initialization_data) structure that supplies the DirectX graphics kernel subsystem with pointers to functions implemented by the KMDOD.

## Return value

 Returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in Ntstatus.h.

## Remarks

All parameters that are supplied by the KMDOD can be in paged memory.

## See also

[DRIVER_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object)

[DriverEntry of Display Miniport Driver](https://learn.microsoft.com/windows-hardware/drivers/display/driverentry-of-display-miniport-driver)

[DxgkInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nf-dispmprt-dxgkinitialize)

[KMDDOD_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_kmddod_initialization_data)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)