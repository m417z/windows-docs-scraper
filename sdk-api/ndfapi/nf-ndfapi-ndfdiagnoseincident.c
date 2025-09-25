void NdfDiagnoseIncident(
  [in]  NDFHANDLE     Handle,
  [out] ULONG         *RootCauseCount,
  [out] RootCauseInfo **RootCauses,
        DWORD         dwWait,
        DWORD         dwFlags
);