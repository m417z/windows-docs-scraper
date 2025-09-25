# _KMCL_SERVER_ONLY_METHODS structure

## Description

The **KMCL_SERVER_ONLY_METHODS** structure contains function pointers for server-only functions for the VMBus Kernel Mode Client Library (KMCL) interface.

For more information about how to access the KMCL interface, see the Remarks section.

## Members

### `VmbChannelMapGpadl`

A pointer to the [**VmbChannelMapGpadl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_channel_map_gpadl) function.

### `VmbChannelRestoreFromBuffer`

A pointer to the [**VmbChannelRestoreFromBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_channel_restore_from_buffer) function.

### `VmbChannelSaveBegin`

A pointer to the [**VmbChannelSaveBegin**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_channel_save_begin) function.

### `VmbChannelSaveContinue`

A pointer to the [**VmbChannelSaveContinue**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_channel_save_continue) function.

### `VmbChannelSaveEnd`

A pointer to the [**VmbChannelSaveEnd**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_channel_save_end) function.

### `VmbChannelUnmapGpadl`

A pointer to the [**VmbChannelUnmapGpadl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_channel_unmap_gpadl) function.

### `VmbConvertVmbusHandleToKernelHandle`

A pointer to the [**VmbConvertVmbusHandleToKernelHandle**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_convert_vmbus_handle_to_kernel_handle) function.

### `VmbPacketRestore`

A pointer to the [**VmbPacketRestore**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_packet_restore) function.

### `VmbServerChannelInitSetFlags`

A pointer to the [**VmbServerChannelInitSetFlags**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_server_channel_init_set_flags) function.

### `VmbServerChannelInitSetMmioMegabytes`

A pointer to the [**VmbServerChannelInitSetMmioMegabytes**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_server_channel_init_set_mmio_megabytes) function.

### `VmbServerChannelInitSetSaveRestorePacketCallbacks`

A pointer to the [**VmbServerChannelInitSetSaveRestorePacketCallbacks**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_server_channel_init_set_save_restore_packet_callbacks) function.

### `VmbServerChannelInitSetTargetInterfaceId`

A pointer to the [**VmbServerChannelInitSetTargetInterfaceId**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_server_channel_init_set_target_interface_id) function.

### `VmbServerChannelInitSetTargetVtl`

A pointer to the [**VmbServerChannelInitSetTargetVtl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_server_channel_init_set_target_vtl) function.

### `VmbServerChannelInitSetVmbusHandle`

A pointer to the [**VmbServerChannelInitSetVmbusHandle**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_server_channel_init_set_vmbus_handle) function.

## Remarks

The function pointers in **KMCL_SERVER_ONLY_METHODS** are called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This structure contains function pointers for server-only functions.

To access both client and server-only functions of the KMCL interface, allocate a **KMCL_SERVER_INTERFACE_V1** structure to receive the interface, then call either [**WdfFdoQueryForInterface**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoqueryforinterface) or [**WdfIoTargetQueryForInterface**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetqueryforinterface) with these parameters:
- *InterfaceType* parameter: **KMCL_SERVER_INTERFACE_TYPE**
- *Size* parameter: `sizeof(KMCL_SERVER_INTERFACE_V1)`
- *Version* parameter: **KMCL_SERVER_INTERFACE_VERSION_V1**

The **KMCL_SERVER_INTERFACE_V1** structure is defined as follows for C language code:

```C++
typedef struct _KMCL_SERVER_INTERFACE_V1 {
    KMCL_CLIENT_INTERFACE_V1;
    KMCL_SERVER_ONLY_METHODS;
} KMCL_SERVER_INTERFACE_V1, *PKMCL_SERVER_INTERFACE_V1;
```

If the interface query function succeeds, the **KMCL_SERVER_INTERFACE_V1** structure contains both a [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1) structure and a **KMCL_SERVER_ONLY_METHODS** structure. The **KMCL_SERVER_ONLY_METHODS** structure contains function pointers that you can use to call VMBus KMCL server-only functions.

For KMCL client methods, see the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1) structure.

For more information about driver-defined interfaces, see [Using Driver-Defined Interfaces](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-driver-defined-interfaces).

## See also

[Using Driver-Defined Interfaces](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-driver-defined-interfaces)

[**WdfFdoQueryForInterface**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoqueryforinterface)

[**WdfIoTargetQueryForInterface**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetqueryforinterface)

[**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1)