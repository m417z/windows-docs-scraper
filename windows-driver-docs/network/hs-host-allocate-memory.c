(WINAPI *HS_HOST_ALLOCATE_MEMORY)(
  _In_  HANDLE                        hPluginContext,
  _In_  DWORD                         dwByteCount,
  _Out_ _bcount (dwByteCount) LPVOID* ppvBuffer
);