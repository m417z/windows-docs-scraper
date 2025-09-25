TBS_RESULT Tbsip_Submit_Command(
  [in]      TBS_HCONTEXT         hContext,
  [in]      TBS_COMMAND_LOCALITY Locality,
  [in]      TBS_COMMAND_PRIORITY Priority,
  [in]      PCBYTE               pabCommand,
  [in]      UINT32               cbCommand,
  [out]     PBYTE                pabResult,
  [in, out] PUINT32              pcbResult
);