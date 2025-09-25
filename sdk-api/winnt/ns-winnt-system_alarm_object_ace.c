typedef struct _SYSTEM_ALARM_OBJECT_ACE {
  ACE_HEADER  Header;
  ACCESS_MASK Mask;
  DWORD       Flags;
  GUID        ObjectType;
  GUID        InheritedObjectType;
  DWORD       SidStart;
} SYSTEM_ALARM_OBJECT_ACE, *PSYSTEM_ALARM_OBJECT_ACE;