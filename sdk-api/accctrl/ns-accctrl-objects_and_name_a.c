typedef struct _OBJECTS_AND_NAME_A {
  DWORD          ObjectsPresent;
  SE_OBJECT_TYPE ObjectType;
  LPSTR          ObjectTypeName;
  LPSTR          InheritedObjectTypeName;
  LPSTR          ptstrName;
} OBJECTS_AND_NAME_A, *POBJECTS_AND_NAME_A;