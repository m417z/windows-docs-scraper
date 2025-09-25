typedef struct _ACCESS_DENIED_CALLBACK_OBJECT_ACE {
  ACE_HEADER  Header;
  ACCESS_MASK Mask;
  DWORD       Flags;
  GUID        ObjectType;
  GUID        InheritedObjectType;
  DWORD       SidStart;
} ACCESS_DENIED_CALLBACK_OBJECT_ACE, *PACCESS_DENIED_CALLBACK_OBJECT_ACE;