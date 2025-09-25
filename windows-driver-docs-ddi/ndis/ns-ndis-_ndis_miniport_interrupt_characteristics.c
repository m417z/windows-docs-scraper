typedef struct _NDIS_MINIPORT_INTERRUPT_CHARACTERISTICS {
  NDIS_OBJECT_HEADER                     Header;
  MINIPORT_ISR_HANDLER                   InterruptHandler;
  MINIPORT_INTERRUPT_DPC_HANDLER         InterruptDpcHandler;
  MINIPORT_DISABLE_INTERRUPT_HANDLER     DisableInterruptHandler;
  MINIPORT_ENABLE_INTERRUPT_HANDLER      EnableInterruptHandler;
  BOOLEAN                                MsiSupported;
  BOOLEAN                                MsiSyncWithAllMessages;
  MINIPORT_MSI_ISR_HANDLER               MessageInterruptHandler;
  MINIPORT_MSI_INTERRUPT_DPC_HANDLER     MessageInterruptDpcHandler;
  MINIPORT_DISABLE_MSI_INTERRUPT_HANDLER DisableMessageInterruptHandler;
  MINIPORT_ENABLE_MSI_INTERRUPT_HANDLER  EnableMessageInterruptHandler;
  NDIS_INTERRUPT_TYPE                    InterruptType;
  PIO_INTERRUPT_MESSAGE_INFO             MessageInfoTable;
} NDIS_MINIPORT_INTERRUPT_CHARACTERISTICS, *PNDIS_MINIPORT_INTERRUPT_CHARACTERISTICS;