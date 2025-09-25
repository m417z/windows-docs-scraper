# _KMCL_CLIENT_INTERFACE_V1 structure

## Description

The **KMCL_CLIENT_INTERFACE_V1** structure contains function pointers for client functions for the VMBus Kernel Mode Client Library (KMCL) interface.

For more information about how to access the KMCL interface, see the Remarks section.

## Members

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbChannelAllocate`

A pointer to the [**VmbChannelAllocate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_channel_allocate) function.

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbChannelCleanup`

A pointer to the [**VmbChannelCleanup**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_channel_cleanup) function.

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbChannelCreateGpadlFromBuffer`

A pointer to the [**VmbChannelCreateGpadlFromBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_channel_create_gpadl_from_buffer) function.

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbChannelCreateGpadlFromMdl`

A pointer to the [**VmbChannelCreateGpadlFromMdl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_channel_create_gpadl_from_mdl) function.

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbChannelDeleteGpadl`

A pointer to the [**VmbChannelDeleteGpadl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_channel_delete_gpadl) function.

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbChannelDisable`

A pointer to the [**VmbChannelDisable**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_channel_disable) function.

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbChannelEnable`

A pointer to the [**VmbChannelEnable**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_channel_enable) function.

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbChannelGetInterfaceInstance`

A pointer to the [**VmbChannelGetInterfaceInstance**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_channel_get_interface_instance) function.

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbChannelGetMmioSpace`

A pointer to the [**VmbChannelGetMmioSpace**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_channel_get_mmio_space) function.

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbChannelGetPointer`

A pointer to the [**VmbChannelGetPointer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_channel_get_pointer) function.

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbChannelInitSetClientContextSize`

A pointer to the [**VmbChannelInitSetClientContextSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_channel_init_set_client_context_size) function.

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbChannelInitSetFlags`

A pointer to the [**VmbChannelInitSetFlags**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_channel_init_set_flags) function.

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbChannelInitSetFriendlyName`

A pointer to the [**VmbChannelInitSetFriendlyName**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_channel_init_set_friendly_name) function.

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbChannelInitSetMaximumExternalData`

A pointer to the [**VmbChannelInitSetMaximumExternalData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_channel_init_set_maximum_external_data) function.

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbChannelInitSetMaximumPacketSize`

A pointer to the [**VmbChannelInitSetMaximumPacketSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_channel_init_set_maximum_packet_size) function.

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbChannelInitSetProcessPacketCallbacks`

A pointer to the [**VmbChannelInitSetProcessPacketCallbacks**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_channel_init_set_process_packet_callbacks) function.

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbChannelInitSetStateChangeCallbacks`

A pointer to the [**VmbChannelInitSetStateChangeCallbacks**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_channel_init_set_state_change_callbacks) function.

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbChannelPacketComplete`

A pointer to the [**VmbChannelPacketComplete**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_channel_packet_complete) function.

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbChannelPacketDeferToPassive`

A pointer to the [**VmbChannelPacketDeferToPassive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_channel_packet_defer_to_passive) function.

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbChannelPacketFail`

A pointer to the [**VmbChannelPacketFail**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_channel_packet_fail) function.

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbChannelPacketGetExternalData`

A pointer to the [**VmbChannelPacketGetExternalData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_channel_packet_get_external_data) function.

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbChannelPause`

A pointer to the [**VmbChannelPause**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_channel_pause) function.

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbChannelSendSynchronousRequest`

A pointer to the [**VmbChannelPause**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_channel_send_synchronous_request) function.

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbChannelSetIncomingProcessingAtPassive`

A pointer to the [**VmbChannelSetIncomingProcessingAtPassive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_channel_set_incoming_processing_at_passive) function.

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbChannelSetInterruptLatency`

A pointer to the [**VmbChannelSetInterruptLatency**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_channel_set_interrupt_latency) function.

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbChannelSetPointer`

A pointer to the [**VmbChannelSetPointer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_channel_set_pointer) function.

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbChannelSetTransactionQuota`

A pointer to the [**VmbChannelSetTransactionQuota**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_channel_set_transaction_quota) function.

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbChannelSizeofPacket`

A pointer to the [**VmbChannelSizeofPacket**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_channel_sizeof_packet) function.

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbChannelStart`

A pointer to the [**VmbChannelStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_channel_start) function.

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbClientChannelInitSetRingBufferPageCount`

A pointer to the [**VmbClientChannelInitSetRingBufferPageCount**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_client_channel_init_set_ring_buffer_page_count) function.

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbClientChannelInitSetTargetPnp`

A pointer to the [**VmbClientChannelInitSetTargetPnp**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_client_channel_init_set_target_pnp) function.

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbPacketAllocate`

A pointer to the [**VmbPacketAllocate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_packet_allocate) function.

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbPacketFree`

A pointer to the [**VmbPacketFree**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_packet_free) function.

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbPacketGetChannel`

A pointer to the [**VmbPacketGetChannel**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_packet_get_channel) function.

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbPacketGetPointer`

A pointer to the [**VmbPacketGetPointer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_packet_get_pointer) function.

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbPacketInitialize`

A pointer to the [**VmbPacketInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_packet_initialize) function.

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbPacketSend`

A pointer to the [**VmbPacketSend**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_packet_send) function.

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbPacketSendWithExternalMdl`

A pointer to the [**VmbPacketSendWithExternalMdl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_packet_send_with_external_mdl) function.

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbPacketSendWithExternalPfns`

A pointer to the [**VmbPacketSendWithExternalPfns**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_packet_send_with_external_pfns) function.

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbPacketSetCompletionRoutine`

A pointer to the [**VmbPacketSetCompletionRoutine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_packet_set_completion_routine) function.

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1.VmbPacketSetPointer`

A pointer to the [**VmbPacketSetPointer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_packet_set_pointer) function.

### `_KMCL_SERVER_ONLY_METHODS_V5`

### `_KMCL_SERVER_ONLY_METHODS_V5.VmbServerChannelInitSetSaveRestorePacketCallbacksEx`

### `C_ASSERT`

### `KMCL_CLIENT_INTERFACE_TYPE`

### `_KMCL_CLIENT_INTERFACE_V1`

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V1`

### `_KMCL_CLIENT_INTERFACE_V1.C_ASSERT`

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V2`

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V2._KMCL_CLIENT_INTERFACE_V2`

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V2._KMCL_CLIENT_INTERFACE_V2.VmbChannelPacketGetClientContext`

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V2._KMCL_CLIENT_INTERFACE_V2.VmbChannelGetTargetDeviceObject`

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V2._KMCL_CLIENT_INTERFACE_V2.VmbChannelGetParentDeviceObject`

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V2.C_ASSERT`

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V2._KMCL_CLIENT_INTERFACE_V3`

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V2._KMCL_CLIENT_INTERFACE_V3._KMCL_CLIENT_INTERFACE_V3`

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V2._KMCL_CLIENT_INTERFACE_V3._KMCL_CLIENT_INTERFACE_V3.VmbChannelInitSetBounceBufferSizes`

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V2._KMCL_CLIENT_INTERFACE_V3._KMCL_CLIENT_INTERFACE_V3.VmbChannelAllocateBounceBuffer`

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V2._KMCL_CLIENT_INTERFACE_V3.C_ASSERT`

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V2._KMCL_CLIENT_INTERFACE_V3._KMCL_CLIENT_INTERFACE_V4`

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V2._KMCL_CLIENT_INTERFACE_V3._KMCL_CLIENT_INTERFACE_V4._KMCL_CLIENT_INTERFACE_V4`

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V2._KMCL_CLIENT_INTERFACE_V3._KMCL_CLIENT_INTERFACE_V4._KMCL_CLIENT_INTERFACE_V4.VmbChannelInitSetMaximumPacketCount`

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V2._KMCL_CLIENT_INTERFACE_V3._KMCL_CLIENT_INTERFACE_V4._KMCL_CLIENT_INTERFACE_V4.VmbChannelCreateGpadlFromPfnList`

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V2._KMCL_CLIENT_INTERFACE_V3._KMCL_CLIENT_INTERFACE_V4.C_ASSERT`

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V2._KMCL_CLIENT_INTERFACE_V3._KMCL_CLIENT_INTERFACE_V4._KMCL_CLIENT_INTERFACE_V5`

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V2._KMCL_CLIENT_INTERFACE_V3._KMCL_CLIENT_INTERFACE_V4._KMCL_CLIENT_INTERFACE_V5._KMCL_CLIENT_INTERFACE_V5`

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V2._KMCL_CLIENT_INTERFACE_V3._KMCL_CLIENT_INTERFACE_V4._KMCL_CLIENT_INTERFACE_V5._KMCL_CLIENT_INTERFACE_V5.VmbChannelInitSetPrimaryChannel`

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V2._KMCL_CLIENT_INTERFACE_V3._KMCL_CLIENT_INTERFACE_V4._KMCL_CLIENT_INTERFACE_V5._KMCL_CLIENT_INTERFACE_V5.VmbChannelInitialize`

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V2._KMCL_CLIENT_INTERFACE_V3._KMCL_CLIENT_INTERFACE_V4._KMCL_CLIENT_INTERFACE_V5._KMCL_CLIENT_INTERFACE_V5.VmbChannelSetAllowableDpcCpuUsage`

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V2._KMCL_CLIENT_INTERFACE_V3._KMCL_CLIENT_INTERFACE_V4._KMCL_CLIENT_INTERFACE_V5._KMCL_CLIENT_INTERFACE_V5.VmbClientChannelInitSetTargetProcessorIndex`

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V2._KMCL_CLIENT_INTERFACE_V3._KMCL_CLIENT_INTERFACE_V4._KMCL_CLIENT_INTERFACE_V5._KMCL_CLIENT_INTERFACE_V5.VmbSizeofChannel`

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V2._KMCL_CLIENT_INTERFACE_V3._KMCL_CLIENT_INTERFACE_V4._KMCL_CLIENT_INTERFACE_V5._KMCL_CLIENT_INTERFACE_V5.VmbChannelInitSetInlinePacketContextSize`

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V2._KMCL_CLIENT_INTERFACE_V3._KMCL_CLIENT_INTERFACE_V4._KMCL_CLIENT_INTERFACE_V5._KMCL_CLIENT_INTERFACE_V5.VmbPacketGetInlinePacketContextPointer`

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V2._KMCL_CLIENT_INTERFACE_V3._KMCL_CLIENT_INTERFACE_V4._KMCL_CLIENT_INTERFACE_V5._KMCL_CLIENT_INTERFACE_V5.VmbChannelInitSetProcessPacketCallbacksEx`

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V2._KMCL_CLIENT_INTERFACE_V3._KMCL_CLIENT_INTERFACE_V4._KMCL_CLIENT_INTERFACE_V5._KMCL_CLIENT_INTERFACE_V5.VmbPacketSetCompletionRoutineEx`

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V2._KMCL_CLIENT_INTERFACE_V3._KMCL_CLIENT_INTERFACE_V4._KMCL_CLIENT_INTERFACE_V5.C_ASSERT`

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V2._KMCL_CLIENT_INTERFACE_V3._KMCL_CLIENT_INTERFACE_V4._KMCL_CLIENT_INTERFACE_V5.KMCL_SERVER_INTERFACE_TYPE`

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V2._KMCL_CLIENT_INTERFACE_V3._KMCL_CLIENT_INTERFACE_V4._KMCL_CLIENT_INTERFACE_V5._KMCL_SERVER_INTERFACE_V1`

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V2._KMCL_CLIENT_INTERFACE_V3._KMCL_CLIENT_INTERFACE_V4._KMCL_CLIENT_INTERFACE_V5._KMCL_SERVER_INTERFACE_V1._KMCL_SERVER_INTERFACE_V1`

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V2._KMCL_CLIENT_INTERFACE_V3._KMCL_CLIENT_INTERFACE_V4._KMCL_CLIENT_INTERFACE_V5._KMCL_SERVER_INTERFACE_V1.C_ASSERT`

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V2._KMCL_CLIENT_INTERFACE_V3._KMCL_CLIENT_INTERFACE_V4._KMCL_CLIENT_INTERFACE_V5._KMCL_SERVER_INTERFACE_V1._KMCL_SERVER_INTERFACE_V5`

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V2._KMCL_CLIENT_INTERFACE_V3._KMCL_CLIENT_INTERFACE_V4._KMCL_CLIENT_INTERFACE_V5._KMCL_SERVER_INTERFACE_V1._KMCL_SERVER_INTERFACE_V5._KMCL_SERVER_INTERFACE_V5`

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V2._KMCL_CLIENT_INTERFACE_V3._KMCL_CLIENT_INTERFACE_V4._KMCL_CLIENT_INTERFACE_V5._KMCL_SERVER_INTERFACE_V1._KMCL_SERVER_INTERFACE_V5.C_ASSERT`

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V2._KMCL_CLIENT_INTERFACE_V3._KMCL_CLIENT_INTERFACE_V4._KMCL_CLIENT_INTERFACE_V5._KMCL_SERVER_INTERFACE_V1._KMCL_SERVER_INTERFACE_V5.KMCL_CLIENT_INTERFACE_V5`

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V2._KMCL_CLIENT_INTERFACE_V3._KMCL_CLIENT_INTERFACE_V4._KMCL_CLIENT_INTERFACE_V5._KMCL_SERVER_INTERFACE_V1._KMCL_SERVER_INTERFACE_V5.KMCL_SERVER_ONLY_METHODS`

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V2._KMCL_CLIENT_INTERFACE_V3._KMCL_CLIENT_INTERFACE_V4._KMCL_CLIENT_INTERFACE_V5.KMCL_CLIENT_INTERFACE_V4`

### `_KMCL_CLIENT_INTERFACE_V1._KMCL_CLIENT_INTERFACE_V2._KMCL_CLIENT_INTERFACE_V3.KMCL_CLIENT_INTERFACE_V2`

### `_KMCL_CLIENT_INTERFACE_V1.INTERFACE`

## Syntax

```cpp
typedef struct _KMCL_CLIENT_INTERFACE_V1 {
    INTERFACE;
    PFN_VMB_CHANNEL_ALLOCATE                                         VmbChannelAllocate;
    PFN_VMB_CHANNEL_CLEANUP                                          VmbChannelCleanup;
    PFN_VMB_CHANNEL_CREATE_GPADL_FROM_BUFFER                         VmbChannelCreateGpadlFromBuffer;
    PFN_VMB_CHANNEL_CREATE_GPADL_FROM_MDL                            VmbChannelCreateGpadlFromMdl;
    PFN_VMB_CHANNEL_DELETE_GPADL                                     VmbChannelDeleteGpadl;
    PFN_VMB_CHANNEL_DISABLE                                          VmbChannelDisable;
    PFN_VMB_CHANNEL_ENABLE                                           VmbChannelEnable;
    PFN_VMB_CHANNEL_GET_INTERFACE_INSTANCE                           VmbChannelGetInterfaceInstance;
    PFN_VMB_CHANNEL_GET_MMIO_SPACE                                   VmbChannelGetMmioSpace;
    PFN_VMB_CHANNEL_GET_POINTER                                      VmbChannelGetPointer;
    PFN_VMB_CHANNEL_INIT_SET_CLIENT_CONTEXT_SIZE                     VmbChannelInitSetClientContextSize;
    PFN_VMB_CHANNEL_INIT_SET_FLAGS                                   VmbChannelInitSetFlags;
    PFN_VMB_CHANNEL_INIT_SET_FRIENDLY_NAME                           VmbChannelInitSetFriendlyName;
    PFN_VMB_CHANNEL_INIT_SET_MAXIMUM_EXTERNAL_DATA                   VmbChannelInitSetMaximumExternalData;
    PFN_VMB_CHANNEL_INIT_SET_MAXIMUM_PACKET_SIZE                     VmbChannelInitSetMaximumPacketSize;
    PFN_VMB_CHANNEL_INIT_SET_PROCESS_PACKET_CALLBACKS                VmbChannelInitSetProcessPacketCallbacks;
    PFN_VMB_CHANNEL_INIT_SET_STATE_CHANGE_CALLBACKS                  VmbChannelInitSetStateChangeCallbacks;
    PFN_VMB_CHANNEL_PACKET_COMPLETE                                  VmbChannelPacketComplete;
    PFN_VMB_CHANNEL_PACKET_DEFER_TO_PASSIVE                          VmbChannelPacketDeferToPassive;
    PFN_VMB_CHANNEL_PACKET_FAIL                                      VmbChannelPacketFail;
    PFN_VMB_CHANNEL_PACKET_GET_EXTERNAL_DATA                         VmbChannelPacketGetExternalData;
    PFN_VMB_CHANNEL_PAUSE                                            VmbChannelPause;
    PFN_VMB_CHANNEL_SEND_SYNCHRONOUS_REQUEST                         VmbChannelSendSynchronousRequest;
    PFN_VMB_CHANNEL_SET_INCOMING_PROCESSING_AT_PASSIVE               VmbChannelSetIncomingProcessingAtPassive;
    PFN_VMB_CHANNEL_SET_INTERRUPT_LATENCY                            VmbChannelSetInterruptLatency;
    PFN_VMB_CHANNEL_SET_POINTER                                      VmbChannelSetPointer;
    PFN_VMB_CHANNEL_SET_TRANSACTION_QUOTA                            VmbChannelSetTransactionQuota;
    PFN_VMB_CHANNEL_SIZEOF_PACKET                                    VmbChannelSizeofPacket;
    PFN_VMB_CHANNEL_START                                            VmbChannelStart;
    PFN_VMB_CLIENT_CHANNEL_INIT_SET_RING_BUFFER_PAGE_COUNT           VmbClientChannelInitSetRingBufferPageCount;
    PFN_VMB_CLIENT_CHANNEL_INIT_SET_TARGET_PNP                       VmbClientChannelInitSetTargetPnp;
    PFN_VMB_PACKET_ALLOCATE                                          VmbPacketAllocate;
    PFN_VMB_PACKET_FREE                                              VmbPacketFree;
    PFN_VMB_PACKET_GET_CHANNEL                                       VmbPacketGetChannel;
    PFN_VMB_PACKET_GET_POINTER                                       VmbPacketGetPointer;
    PFN_VMB_PACKET_INITIALIZE                                        VmbPacketInitialize;
    PFN_VMB_PACKET_SEND                                              VmbPacketSend;
    PFN_VMB_PACKET_SEND_WITH_EXTERNAL_MDL                            VmbPacketSendWithExternalMdl;
    PFN_VMB_PACKET_SEND_WITH_EXTERNAL_PFNS                           VmbPacketSendWithExternalPfns;
    PFN_VMB_PACKET_SET_COMPLETION_ROUTINE                            VmbPacketSetCompletionRoutine;
    PFN_VMB_PACKET_SET_POINTER                                       VmbPacketSetPointer;

} KMCL_CLIENT_INTERFACE_V1, *PKMCL_CLIENT_INTERFACE_V1;
```

## Remarks

The first member of this structure is an [**INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface) structure that describes the KMCL interface exported by the Vmbuskmcl.sys bus driver.

The function pointers in **KMCL_CLIENT_INTERFACE_V1** are called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This structure contains function pointers for client functions.

To access client functions of the KMCL interface, allocate a **KMCL_CLIENT_INTERFACE_V1** structure to receive the interface, then call either [**WdfFdoQueryForInterface**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoqueryforinterface) or [**WdfIoTargetQueryForInterface**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetqueryforinterface) with these parameters:
- *InterfaceType* parameter: **KMCL_CLIENT_INTERFACE_TYPE**
- *Size* parameter: `sizeof(KMCL_CLIENT_INTERFACE_V1)`
- *Version* parameter: **KMCL_CLIENT_INTERFACE_VERSION_V1**

If the interface query function succeeds, the **KMCL_CLIENT_INTERFACE_V1** structure contains function pointers that you can use to call VMBus KMCL client functions.

For server-only methods, see the [**KMCL_SERVER_ONLY_METHODS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_server_only_methods) structure.

For more information about driver-defined interfaces, see [Using Driver-Defined Interfaces](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-driver-defined-interfaces).

## See also

[Using Driver-Defined Interfaces](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-driver-defined-interfaces)

[**WdfFdoQueryForInterface**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoqueryforinterface)

[**WdfIoTargetQueryForInterface**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetqueryforinterface)

[**KMCL_SERVER_ONLY_METHODS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_server_only_methods)