BOOL SaferGetLevelInformation(
  [in]            SAFER_LEVEL_HANDLE      LevelHandle,
  [in]            SAFER_OBJECT_INFO_CLASS dwInfoType,
  [out, optional] LPVOID                  lpQueryBuffer,
  [in]            DWORD                   dwInBufferSize,
  [out]           LPDWORD                 lpdwOutBufferSize
);