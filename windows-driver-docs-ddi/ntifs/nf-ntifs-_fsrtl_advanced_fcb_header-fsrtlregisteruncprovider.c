NTSTATUS FsRtlRegisterUncProvider(
  [out] PHANDLE          MupHandle,
        PCUNICODE_STRING RedirectorDeviceName,
  [in]  BOOLEAN          MailslotsSupported
);