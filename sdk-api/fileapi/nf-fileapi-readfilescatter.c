BOOL ReadFileScatter(
  [in]      HANDLE                  hFile,
  [in]      FILE_SEGMENT_ELEMENT [] aSegmentArray,
  [in]      DWORD                   nNumberOfBytesToRead,
            LPDWORD                 lpReserved,
  [in, out] LPOVERLAPPED            lpOverlapped
);