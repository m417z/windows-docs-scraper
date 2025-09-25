PFAXGETPAGEDATA Pfaxgetpagedata;

BOOL Pfaxgetpagedata(
  [in]  HANDLE FaxHandle,
  [in]  DWORD JobId,
  [out] LPBYTE *Buffer,
  [out] LPDWORD BufferSize,
  [out] LPDWORD ImageWidth,
  [out] LPDWORD ImageHeight
)
{...}