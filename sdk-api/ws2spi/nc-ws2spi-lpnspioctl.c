LPNSPIOCTL Lpnspioctl;

INT Lpnspioctl(
  [in]      HANDLE hLookup,
  [in]      DWORD dwControlCode,
  [in]      LPVOID lpvInBuffer,
  [in, out] DWORD cbInBuffer,
  [out]     LPVOID lpvOutBuffer,
  [in]      DWORD cbOutBuffer,
  [out]     LPDWORD lpcbBytesReturned,
  [in]      LPWSACOMPLETION lpCompletion,
  [in]      LPWSATHREADID lpThreadId
)
{...}