ULONG WMIAPI RegisterTraceGuidsA(
  [in]      WMIDPREQUEST             RequestAddress,
  [in]      PVOID                    RequestContext,
  [in]      LPCGUID                  ControlGuid,
  [in]      ULONG                    GuidCount,
  [in, out] PTRACE_GUID_REGISTRATION TraceGuidReg,
  [in]      LPCSTR                   MofImagePath,
  [in]      LPCSTR                   MofResourceName,
  [out]     TRACEGUID_HANDLE         *RegistrationHandle
);