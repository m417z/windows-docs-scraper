NTSYSAPI NTSTATUS ZwCreateKey(
  [out]           PHANDLE            KeyHandle,
  [in]            ACCESS_MASK        DesiredAccess,
  [in]            POBJECT_ATTRIBUTES ObjectAttributes,
                  ULONG              TitleIndex,
  [in, optional]  PUNICODE_STRING    Class,
  [in]            ULONG              CreateOptions,
  [out, optional] PULONG             Disposition
);