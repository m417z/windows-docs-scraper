typedef struct {
  PDRIVER_DISPATCH     Create;
  PVOID                Context;
  UNICODE_STRING       ObjectClass;
  PSECURITY_DESCRIPTOR SecurityDescriptor;
  ULONG                Flags;
} KSOBJECT_CREATE_ITEM, *PKSOBJECT_CREATE_ITEM;