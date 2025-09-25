ULONG WMIAPI RegisterTraceGuidsW(
  [in]      WMIDPREQUEST             RequestAddress,
  [in]      PVOID                    RequestContext,
  [in]      LPCGUID                  ControlGuid,
  [in]      ULONG                    GuidCount,
  [in, out] PTRACE_GUID_REGISTRATION TraceGuidReg,
  [in]      LPCWSTR                  MofImagePath,
  [in]      LPCWSTR                  MofResourceName,
  [out]     TRACEGUID_HANDLE         *RegistrationHandle
);