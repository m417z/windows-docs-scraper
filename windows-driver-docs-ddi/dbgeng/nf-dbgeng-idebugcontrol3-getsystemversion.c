HRESULT GetSystemVersion(
  [out]           PULONG PlatformId,
  [out]           PULONG Major,
  [out]           PULONG Minor,
  [out, optional] PSTR   ServicePackString,
  [in]            ULONG  ServicePackStringSize,
  [out, optional] PULONG ServicePackStringUsed,
  [out]           PULONG ServicePackNumber,
  [out, optional] PSTR   BuildString,
  [in]            ULONG  BuildStringSize,
  [out, optional] PULONG BuildStringUsed
);