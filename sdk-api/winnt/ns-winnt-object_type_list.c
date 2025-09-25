typedef struct _OBJECT_TYPE_LIST {
  WORD Level;
  WORD Sbz;
  GUID *ObjectType;
} OBJECT_TYPE_LIST, *POBJECT_TYPE_LIST;