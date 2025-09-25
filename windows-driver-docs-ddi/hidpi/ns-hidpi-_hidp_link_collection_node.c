typedef struct _HIDP_LINK_COLLECTION_NODE {
  USAGE  LinkUsage;
  USAGE  LinkUsagePage;
  USHORT Parent;
  USHORT NumberOfChildren;
  USHORT NextSibling;
  USHORT FirstChild;
  ULONG  CollectionType : 8;
  ULONG  IsAlias : 1;
  ULONG  Reserved : 23;
  PVOID  UserContext;
} HIDP_LINK_COLLECTION_NODE, *PHIDP_LINK_COLLECTION_NODE;