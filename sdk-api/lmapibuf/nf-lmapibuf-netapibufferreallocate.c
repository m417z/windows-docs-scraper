NET_API_STATUS NET_API_FUNCTION NetApiBufferReallocate(
  [in]  _Frees_ptr_opt_ LPVOID OldBuffer,
  [in]  DWORD                  NewByteCount,
  [out] LPVOID                 *NewBuffer
);