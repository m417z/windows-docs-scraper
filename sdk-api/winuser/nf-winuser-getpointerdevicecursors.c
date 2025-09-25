BOOL GetPointerDeviceCursors(
  [in]            HANDLE                     device,
  [in, out]       UINT32                     *cursorCount,
  [out, optional] POINTER_DEVICE_CURSOR_INFO *deviceCursors
);