VOID BuildTrusteeWithObjectsAndNameW(
  [in, out]      PTRUSTEE_W          pTrustee,
  [in, optional] POBJECTS_AND_NAME_W pObjName,
  [in, optional] SE_OBJECT_TYPE      ObjectType,
  [in, optional] LPWSTR              ObjectTypeName,
  [in, optional] LPWSTR              InheritedObjectTypeName,
  [in, optional] LPWSTR              Name
);