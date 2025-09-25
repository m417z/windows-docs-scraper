PFN_DrvWriteAbortBuf PfnDrvwriteabortbuf;

DWORD PfnDrvwriteabortbuf(
  PDEVOBJ pdevobj,
  PVOID pBuffer,
  DWORD cbSize,
  DWORD dwWait
)
{...}