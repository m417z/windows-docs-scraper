NTSTATUS FLTAPI FltDecodeParameters(
  [in]            PFLT_CALLBACK_DATA CallbackData,
  [out]           PMDL               **MdlAddressPointer,
  [out]           PVOID              **Buffer,
  [out]           PULONG             *Length,
  [out, optional] LOCK_OPERATION     *DesiredAccess
);