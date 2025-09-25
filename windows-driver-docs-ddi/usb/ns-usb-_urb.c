typedef struct _URB {
  union {
#if ...
    _URB_HEADER                                     UrbHeader;
#else
    struct _URB_HEADER                              UrbHeader;
#endif
#if ...
    _URB_SELECT_INTERFACE                           UrbSelectInterface;
#else
    struct _URB_SELECT_INTERFACE                    UrbSelectInterface;
#endif
#if ...
    _URB_SELECT_CONFIGURATION                       UrbSelectConfiguration;
#else
    struct _URB_SELECT_CONFIGURATION                UrbSelectConfiguration;
#endif
#if ...
    _URB_PIPE_REQUEST                               UrbPipeRequest;
#else
    struct _URB_PIPE_REQUEST                        UrbPipeRequest;
#endif
#if ...
    _URB_FRAME_LENGTH_CONTROL                       UrbFrameLengthControl;
#else
    struct _URB_FRAME_LENGTH_CONTROL                UrbFrameLengthControl;
#endif
#if ...
    _URB_GET_FRAME_LENGTH                           UrbGetFrameLength;
#else
    struct _URB_GET_FRAME_LENGTH                    UrbGetFrameLength;
#endif
#if ...
    _URB_SET_FRAME_LENGTH                           UrbSetFrameLength;
#else
    struct _URB_SET_FRAME_LENGTH                    UrbSetFrameLength;
#endif
#if ...
    _URB_GET_CURRENT_FRAME_NUMBER                   UrbGetCurrentFrameNumber;
#else
    struct _URB_GET_CURRENT_FRAME_NUMBER            UrbGetCurrentFrameNumber;
#endif
#if ...
    _URB_CONTROL_TRANSFER                           UrbControlTransfer;
#else
    struct _URB_CONTROL_TRANSFER                    UrbControlTransfer;
#endif
#if ...
    _URB_CONTROL_TRANSFER_EX                        UrbControlTransferEx;
#else
    struct _URB_CONTROL_TRANSFER_EX                 UrbControlTransferEx;
#endif
#if ...
    _URB_BULK_OR_INTERRUPT_TRANSFER                 UrbBulkOrInterruptTransfer;
#else
    struct _URB_BULK_OR_INTERRUPT_TRANSFER          UrbBulkOrInterruptTransfer;
#endif
#if ...
    _URB_ISOCH_TRANSFER                             UrbIsochronousTransfer;
#else
    struct _URB_ISOCH_TRANSFER                      UrbIsochronousTransfer;
#endif
#if ...
    _URB_CONTROL_DESCRIPTOR_REQUEST                 UrbControlDescriptorRequest;
#else
    struct _URB_CONTROL_DESCRIPTOR_REQUEST          UrbControlDescriptorRequest;
#endif
#if ...
    _URB_CONTROL_GET_STATUS_REQUEST                 UrbControlGetStatusRequest;
#else
    struct _URB_CONTROL_GET_STATUS_REQUEST          UrbControlGetStatusRequest;
#endif
#if ...
    _URB_CONTROL_FEATURE_REQUEST                    UrbControlFeatureRequest;
#else
    struct _URB_CONTROL_FEATURE_REQUEST             UrbControlFeatureRequest;
#endif
#if ...
    _URB_CONTROL_VENDOR_OR_CLASS_REQUEST            UrbControlVendorClassRequest;
#else
    struct _URB_CONTROL_VENDOR_OR_CLASS_REQUEST     UrbControlVendorClassRequest;
#endif
#if ...
    _URB_CONTROL_GET_INTERFACE_REQUEST              UrbControlGetInterfaceRequest;
#else
    struct _URB_CONTROL_GET_INTERFACE_REQUEST       UrbControlGetInterfaceRequest;
#endif
#if ...
    _URB_CONTROL_GET_CONFIGURATION_REQUEST          UrbControlGetConfigurationRequest;
#else
    struct _URB_CONTROL_GET_CONFIGURATION_REQUEST   UrbControlGetConfigurationRequest;
#endif
#if ...
    _URB_OS_FEATURE_DESCRIPTOR_REQUEST              UrbOSFeatureDescriptorRequest;
#else
    struct _URB_OS_FEATURE_DESCRIPTOR_REQUEST       UrbOSFeatureDescriptorRequest;
#endif
#if ...
    _URB_OPEN_STATIC_STREAMS                        UrbOpenStaticStreams;
#else
    struct _URB_OPEN_STATIC_STREAMS                 UrbOpenStaticStreams;
#endif
#if ...
    _URB_GET_ISOCH_PIPE_TRANSFER_PATH_DELAYS        UrbGetIsochPipeTransferPathDelays;
#else
    struct _URB_GET_ISOCH_PIPE_TRANSFER_PATH_DELAYS UrbGetIsochPipeTransferPathDelays;
#endif
  };
} URB, *PURB;