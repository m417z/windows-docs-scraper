typedef struct _BRB {
  union {
#if ...
    _BRB_HEADER                             BrbHeader;
#else
    struct _BRB_HEADER                      BrbHeader;
#endif
#if ...
    _BRB_GET_DEVICE_INTERFACE_STRING        BrbGetDeviceInterfaceString;
#else
    struct _BRB_GET_DEVICE_INTERFACE_STRING BrbGetDeviceInterfaceString;
#endif
#if ...
    _BRB_GET_LOCAL_BD_ADDR                  BrbGetLocalBdAddress;
#else
    struct _BRB_GET_LOCAL_BD_ADDR           BrbGetLocalBdAddress;
#endif
#if ...
    _BRB_ACL_GET_MODE                       BrbAclGetMode;
#else
    struct _BRB_ACL_GET_MODE                BrbAclGetMode;
#endif
#if ...
    _BRB_ACL_ENTER_ACTIVE_MODE              BrbAclEnterActiveMode;
#else
    struct _BRB_ACL_ENTER_ACTIVE_MODE       BrbAclEnterActiveMode;
#endif
#if ...
    _BRB_PSM                                BrbPsm;
#else
    struct _BRB_PSM                         BrbPsm;
#endif
#if ...
    _BRB_L2CA_REGISTER_SERVER               BrbL2caRegisterServer;
#else
    struct _BRB_L2CA_REGISTER_SERVER        BrbL2caRegisterServer;
#endif
#if ...
    _BRB_L2CA_UNREGISTER_SERVER             BrbL2caUnregisterServer;
#else
    struct _BRB_L2CA_UNREGISTER_SERVER      BrbL2caUnregisterServer;
#endif
#if ...
    _BRB_L2CA_OPEN_CHANNEL                  BrbL2caOpenChannel;
#else
    struct _BRB_L2CA_OPEN_CHANNEL           BrbL2caOpenChannel;
#endif
#if ...
    _BRB_L2CA_CLOSE_CHANNEL                 BrbL2caCloseChannel;
#else
    struct _BRB_L2CA_CLOSE_CHANNEL          BrbL2caCloseChannel;
#endif
#if ...
    _BRB_L2CA_PING                          BrbL2caPing;
#else
    struct _BRB_L2CA_PING                   BrbL2caPing;
#endif
#if ...
    _BRB_L2CA_ACL_TRANSFER                  BrbL2caAclTransfer;
#else
    struct _BRB_L2CA_ACL_TRANSFER           BrbL2caAclTransfer;
#endif
#if ...
    _BRB_L2CA_UPDATE_CHANNEL                BrbL2caUpdateChannel;
#else
    struct _BRB_L2CA_UPDATE_CHANNEL         BrbL2caUpdateChannel;
#endif
#if ...
    _BRB_L2CA_OPEN_ENHANCED_CHANNEL         BrbL2caOpenEnhancedChannel;
#else
    struct _BRB_L2CA_OPEN_ENHANCED_CHANNEL  BrbL2caOpenEnhancedChannel;
#endif
#if ...
    _BRB_SCO_REGISTER_SERVER                BrbScoRegisterServer;
#else
    struct _BRB_SCO_REGISTER_SERVER         BrbScoRegisterServer;
#endif
#if ...
    _BRB_SCO_UNREGISTER_SERVER              BrbScoUnregisterServer;
#else
    struct _BRB_SCO_UNREGISTER_SERVER       BrbScoUnregisterServer;
#endif
#if ...
    _BRB_SCO_OPEN_CHANNEL                   BrbScoOpenChannel;
#else
    struct _BRB_SCO_OPEN_CHANNEL            BrbScoOpenChannel;
#endif
#if ...
    _BRB_SCO_CLOSE_CHANNEL                  BrbScoCloseChannel;
#else
    struct _BRB_SCO_CLOSE_CHANNEL           BrbScoCloseChannel;
#endif
#if ...
    _BRB_SCO_FLUSH_CHANNEL                  BrbScoFlushChannel;
#else
    struct _BRB_SCO_FLUSH_CHANNEL           BrbScoFlushChannel;
#endif
#if ...
    _BRB_SCO_TRANSFER                       BrbScoTransfer;
#else
    struct _BRB_SCO_TRANSFER                BrbScoTransfer;
#endif
#if ...
    _BRB_SCO_GET_CHANNEL_INFO               BrbScoGetChannelInfo;
#else
    struct _BRB_SCO_GET_CHANNEL_INFO        BrbScoGetChannelInfo;
#endif
#if ...
    _BRB_SCO_GET_SYSTEM_INFO                BrbScoGetSystemInfo;
#else
    struct _BRB_SCO_GET_SYSTEM_INFO         BrbScoGetSystemInfo;
#endif
  };
} BRB, *PBRB;