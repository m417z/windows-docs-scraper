NTSTATUS LsaRegisterLogonProcess(
  [in]  PLSA_STRING           LogonProcessName,
  [out] PHANDLE               LsaHandle,
  [out] PLSA_OPERATIONAL_MODE SecurityMode
);