typedef struct _KMCL_SERVER_ONLY_METHODS {
  PFN_VMB_CHANNEL_MAP_GPADL                                     VmbChannelMapGpadl;
  PFN_VMB_CHANNEL_RESTORE_FROM_BUFFER                           VmbChannelRestoreFromBuffer;
  PFN_VMB_CHANNEL_SAVE_BEGIN                                    VmbChannelSaveBegin;
  PFN_VMB_CHANNEL_SAVE_CONTINUE                                 VmbChannelSaveContinue;
  PFN_VMB_CHANNEL_SAVE_END                                      VmbChannelSaveEnd;
  PFN_VMB_CHANNEL_UNMAP_GPADL                                   VmbChannelUnmapGpadl;
  PFN_VMB_CONVERT_VMBUS_HANDLE_TO_KERNEL_HANDLE                 VmbConvertVmbusHandleToKernelHandle;
  PFN_VMB_PACKET_RESTORE                                        VmbPacketRestore;
  PFN_VMB_SERVER_CHANNEL_INIT_SET_FLAGS                         VmbServerChannelInitSetFlags;
  PFN_VMB_SERVER_CHANNEL_INIT_SET_MMIO_MEGABYTES                VmbServerChannelInitSetMmioMegabytes;
  PFN_VMB_SERVER_CHANNEL_INIT_SET_SAVE_RESTORE_PACKET_CALLBACKS VmbServerChannelInitSetSaveRestorePacketCallbacks;
  PFN_VMB_SERVER_CHANNEL_INIT_SET_TARGET_INTERFACE_ID           VmbServerChannelInitSetTargetInterfaceId;
  PFN_VMB_SERVER_CHANNEL_INIT_SET_TARGET_VTL                    VmbServerChannelInitSetTargetVtl;
  PFN_VMB_SERVER_CHANNEL_INIT_SET_VMBUS_HANDLE                  VmbServerChannelInitSetVmbusHandle;
} KMCL_SERVER_ONLY_METHODS;