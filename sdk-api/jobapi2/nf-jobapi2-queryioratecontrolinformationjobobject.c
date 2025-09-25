DWORD QueryIoRateControlInformationJobObject(
  [in, optional] HANDLE                                hJob,
  [in, optional] PCWSTR                                VolumeName,
  [out]          JOBOBJECT_IO_RATE_CONTROL_INFORMATION **InfoBlocks,
  [out]          ULONG                                 *InfoBlockCount
);