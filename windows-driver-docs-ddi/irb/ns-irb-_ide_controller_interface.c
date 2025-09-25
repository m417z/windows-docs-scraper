typedef struct _IDE_CONTROLLER_INTERFACE {
  USHORT                   Version;
  USHORT                   Reserved;
  ULONG                    ControllerExtensionSize;
  ULONG                    ChannelExtensionSize;
  ULONG                    AlignmentMask;
  IDE_CHANNEL_INIT         AtaChannelInitRoutine;
  IDE_CHANNEL_ENABLED      AtaControllerChannelEnabled;
  IDE_TRANSFER_MODE_SELECT AtaControllerTransferModeSelect;
  IDE_ADAPTER_CONTROL      AtaAdapterControl;
} IDE_CONTROLLER_INTERFACE, *PIDE_CONTROLLER_INTERFACE;