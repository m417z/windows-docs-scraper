# QUERY_INTERFACE structure

## Description

The **QUERY_INTERFACE** structure describes the interface being requested.

## Members

### `InterfaceType`

Pointer to a GUID that identifies the interface being requested. If the kernel-mode display miniport driver (KMD) (or [legacy video miniport driver](https://learn.microsoft.com/previous-versions/windows/drivers/display/video-miniport-driver-within-the-graphics-architecture--windows-2000-m)) doesn't support the specified **InterfaceType**, it should fail the call and return immediately.

The parent generates this GUID with *uuidgen.exe*. See [Defining and Exporting New GUIDs](https://learn.microsoft.com/windows-hardware/drivers/kernel/defining-and-exporting-new-guids) for details.

### `Size`

Specifies the size in bytes of the [**INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface) structure to which **Interface** points. The driver must not return an **INTERFACE** structure larger than **Size** bytes.

### `Version`

Specifies the version of the interface being requested.

If a parent supports more than one version of an interface, its driver should return the specified version or, if possible, the closest supported version without exceeding the requested version. The caller is responsible for examining the returned **Version** and determine what to do based on that value.

### `Interface`

Pointer to an [**INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface) structure in which the driver returns the requested interface information. The caller is responsible for allocating this structure before calling [**DxgkddiQueryInterface**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_interface) (or [**HwVidQueryInterface**](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_query_interface)).

### `InterfaceSpecificData`

Specifies additional information about the interface being requested. Typically, this member is NULL, and the **InterfaceType** and **Version** members are sufficient for the parent to identify the interface being requested.

### `DeviceUid`

A positive integer that identifies the device for which the interface is being queried. If **DeviceUid** is equal to DISPLAY_ADAPTER_HW_ID (defined in *Video.h*), the device is the display adapter itself. Otherwise, **DeviceUid** is the identifier of a child device of the display adapter. Child device identifiers were previously assigned by the [**DxgkDdiQueryChildRelations**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations) function. Available starting with Windows 8.1 (WDDM 1.3).

## Remarks

The **QueryInterface** parameter of the KMD's [**DxgkddiQueryInterface**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_interface) callback (or [legacy video miniport driver](https://learn.microsoft.com/previous-versions/windows/drivers/display/video-miniport-driver-within-the-graphics-architecture--windows-2000-m)'s [**HwVidQueryInterface**](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_query_interface) function) is a pointer to a **QUERY_INTERFACE** structure.

## See also

[**DxgkddiQueryInterface**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_interface)

[**HwVidQueryInterface**](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_query_interface)