NTSTATUS FLTAPI FltGetTunneledName(
  [in]  PFLT_CALLBACK_DATA         CallbackData,
  [in]  PFLT_FILE_NAME_INFORMATION FileNameInformation,
  [out] PFLT_FILE_NAME_INFORMATION *RetTunneledFileNameInformation
);