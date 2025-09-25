HRESULT AreCharactersLocal(
  [in]  WCHAR const *characters,
        UINT32      characterCount,
        BOOL        enqueueIfNotLocal,
  [out] BOOL        *isLocal
);