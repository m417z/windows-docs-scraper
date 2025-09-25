typedef struct _PUBLIC_OBJECT_BASIC_INFORMATION {
  ULONG       Attributes;
  ACCESS_MASK GrantedAccess;
  ULONG       HandleCount;
  ULONG       PointerCount;
  ULONG       Reserved[10];
} PUBLIC_OBJECT_BASIC_INFORMATION, *PPUBLIC_OBJECT_BASIC_INFORMATION;