typedef struct _PCMCIA_INTERFACE_STANDARD {
  USHORT                       Size;
  USHORT                       Version;
  PINTERFACE_REFERENCE         InterfaceReference;
  PINTERFACE_DEREFERENCE       InterfaceDereference;
  PVOID                        Context;
  PPCMCIA_MODIFY_MEMORY_WINDOW ModifyMemoryWindow;
  PPCMCIA_SET_VPP              SetVpp;
  PPCMCIA_IS_WRITE_PROTECTED   IsWriteProtected;
} PCMCIA_INTERFACE_STANDARD, *PPCMCIA_INTERFACE_STANDARD;