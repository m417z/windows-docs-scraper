BOOL WriteFileGather(
  [in]      HANDLE                  hFile,
  [in]      FILE_SEGMENT_ELEMENT [] aSegmentArray,
  [in]      DWORD                   nNumberOfBytesToWrite,
            LPDWORD                 lpReserved,
  [in, out] LPOVERLAPPED            lpOverlapped
);