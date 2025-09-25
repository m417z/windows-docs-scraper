typedef struct _GPIO_CLIENT_REGISTRATION_PACKET {
  USHORT                                          Version;
  USHORT                                          Size;
  ULONG                                           Flags;
  ULONG                                           ControllerContextSize;
  ULONG64                                         Reserved;
  PGPIO_CLIENT_PREPARE_CONTROLLER                 CLIENT_PrepareController;
  PGPIO_CLIENT_RELEASE_CONTROLLER                 CLIENT_ReleaseController;
  PGPIO_CLIENT_START_CONTROLLER                   CLIENT_StartController;
  PGPIO_CLIENT_STOP_CONTROLLER                    CLIENT_StopController;
  PGPIO_CLIENT_QUERY_CONTROLLER_BASIC_INFORMATION CLIENT_QueryControllerBasicInformation;
  PGPIO_CLIENT_QUERY_SET_CONTROLLER_INFORMATION   CLIENT_QuerySetControllerInformation;
  PGPIO_CLIENT_ENABLE_INTERRUPT                   CLIENT_EnableInterrupt;
  PGPIO_CLIENT_DISABLE_INTERRUPT                  CLIENT_DisableInterrupt;
  PGPIO_CLIENT_UNMASK_INTERRUPT                   CLIENT_UnmaskInterrupt;
  PGPIO_CLIENT_MASK_INTERRUPTS                    CLIENT_MaskInterrupts;
  PGPIO_CLIENT_QUERY_ACTIVE_INTERRUPTS            CLIENT_QueryActiveInterrupts;
  PGPIO_CLIENT_CLEAR_ACTIVE_INTERRUPTS            CLIENT_ClearActiveInterrupts;
  PGPIO_CLIENT_CONNECT_IO_PINS                    CLIENT_ConnectIoPins;
  PGPIO_CLIENT_DISCONNECT_IO_PINS                 CLIENT_DisconnectIoPins;
  union {
    PGPIO_CLIENT_READ_PINS      CLIENT_ReadGpioPins;
    PGPIO_CLIENT_READ_PINS_MASK CLIENT_ReadGpioPinsUsingMask;
  };
  union {
    PGPIO_CLIENT_WRITE_PINS      CLIENT_WriteGpioPins;
    PGPIO_CLIENT_WRITE_PINS_MASK CLIENT_WriteGpioPinsUsingMask;
  };
  PGPIO_CLIENT_SAVE_BANK_HARDWARE_CONTEXT         CLIENT_SaveBankHardwareContext;
  PGPIO_CLIENT_RESTORE_BANK_HARDWARE_CONTEXT      CLIENT_RestoreBankHardwareContext;
  PGPIO_CLIENT_PRE_PROCESS_CONTROLLER_INTERRUPT   CLIENT_PreProcessControllerInterrupt;
  PGPIO_CLIENT_CONTROLLER_SPECIFIC_FUNCTION       CLIENT_ControllerSpecificFunction;
  PGPIO_CLIENT_RECONFIGURE_INTERRUPT              CLIENT_ReconfigureInterrupt;
  PGPIO_CLIENT_QUERY_ENABLED_INTERRUPTS           CLIENT_QueryEnabledInterrupts;
  PGPIO_CLIENT_CONNECT_FUNCTION_CONFIG_PINS       CLIENT_ConnectFunctionConfigPins;
  PGPIO_CLIENT_DISCONNECT_FUNCTION_CONFIG_PINS    CLIENT_DisconnectFunctionConfigPins;
} GPIO_CLIENT_REGISTRATION_PACKET, *PGPIO_CLIENT_REGISTRATION_PACKET;