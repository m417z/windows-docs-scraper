BOOL MakeSelfRelativeSD(
  [in]            PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor,
  [out, optional] PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,
  [in, out]       LPDWORD              lpdwBufferLength
);