typedef struct _OBJECTS_AND_SID {
  DWORD ObjectsPresent;
  GUID  ObjectTypeGuid;
  GUID  InheritedObjectTypeGuid;
  SID   *pSid;
} OBJECTS_AND_SID, *POBJECTS_AND_SID;