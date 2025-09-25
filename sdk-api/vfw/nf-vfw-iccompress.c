DWORD VFWAPIV ICCompress(
  HIC                hic,
  DWORD              dwFlags,
  LPBITMAPINFOHEADER lpbiOutput,
  LPVOID             lpData,
  LPBITMAPINFOHEADER lpbiInput,
  LPVOID             lpBits,
  LPDWORD            lpckid,
  LPDWORD            lpdwFlags,
  LONG               lFrameNum,
  DWORD              dwFrameSize,
  DWORD              dwQuality,
  LPBITMAPINFOHEADER lpbiPrev,
  LPVOID             lpPrev
);