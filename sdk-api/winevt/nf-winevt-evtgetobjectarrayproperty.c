BOOL EvtGetObjectArrayProperty(
  [in]  EVT_OBJECT_ARRAY_PROPERTY_HANDLE ObjectArray,
  [in]  DWORD                            PropertyId,
  [in]  DWORD                            ArrayIndex,
  [in]  DWORD                            Flags,
  [in]  DWORD                            PropertyValueBufferSize,
  [in]  PEVT_VARIANT                     PropertyValueBuffer,
  [out] PDWORD                           PropertyValueBufferUsed
);