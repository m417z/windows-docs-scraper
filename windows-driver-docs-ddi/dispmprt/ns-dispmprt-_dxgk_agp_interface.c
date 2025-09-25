typedef struct _DXGK_AGP_INTERFACE {
  USHORT                   Size;
  USHORT                   Version;
  PVOID                    Context;
  PINTERFACE_REFERENCE     InterfaceReference;
  PINTERFACE_DEREFERENCE   InterfaceDereference;
  DXGKCB_AGP_ALLOCATE_POOL AgpAllocatePool;
  DXGKCB_AGP_FREE_POOL     AgpFreePool;
  DXGKCB_AGP_SET_COMMAND   AgpSetCommand;
} DXGK_AGP_INTERFACE, *PDXGK_AGP_INTERFACE;