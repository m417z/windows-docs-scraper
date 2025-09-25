EDITSTREAMCALLBACK Editstreamcallback;

DWORD Editstreamcallback(
  [in] DWORD_PTR dwCookie,
  [in] LPBYTE pbBuff,
  [in] LONG cb,
  [in] LONG *pcb
)
{...}