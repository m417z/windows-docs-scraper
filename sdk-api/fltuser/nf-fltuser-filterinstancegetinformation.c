HRESULT FilterInstanceGetInformation(
  [in]  HFILTER_INSTANCE           hInstance,
  [in]  INSTANCE_INFORMATION_CLASS dwInformationClass,
  [out] LPVOID                     lpBuffer,
  [in]  DWORD                      dwBufferSize,
  [out] LPDWORD                    lpBytesReturned
);