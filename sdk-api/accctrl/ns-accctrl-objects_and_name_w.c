typedef struct _OBJECTS_AND_NAME_W {
  DWORD          ObjectsPresent;
  SE_OBJECT_TYPE ObjectType;
  LPWSTR         ObjectTypeName;
  LPWSTR         InheritedObjectTypeName;
  LPWSTR         ptstrName;
} OBJECTS_AND_NAME_W, *POBJECTS_AND_NAME_W;