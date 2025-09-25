DWORD MgmGetNextMfeStats(
  [in]      PMIB_IPMCAST_MFE pimmStart,
  [in, out] PDWORD           pdwBufferSize,
  [in, out] PBYTE            pbBuffer,
  [in, out] PDWORD           pdwNumEntries,
            DWORD            dwFlags
);