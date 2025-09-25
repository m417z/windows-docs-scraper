PTP_IO CreateThreadpoolIo(
  [in]                HANDLE                fl,
  [in]                PTP_WIN32_IO_CALLBACK pfnio,
  [in, out, optional] PVOID                 pv,
  [in, optional]      PTP_CALLBACK_ENVIRON  pcbe
);