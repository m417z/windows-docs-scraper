typedef struct _REENUMERATE_SELF_INTERFACE_STANDARD {
  USHORT                 Size;
  USHORT                 Version;
  PVOID                  Context;
  PINTERFACE_REFERENCE   InterfaceReference;
  PINTERFACE_DEREFERENCE InterfaceDereference;
  PREENUMERATE_SELF      SurpriseRemoveAndReenumerateSelf;
} REENUMERATE_SELF_INTERFACE_STANDARD, *PREENUMERATE_SELF_INTERFACE_STANDARD;