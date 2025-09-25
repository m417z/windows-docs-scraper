NTSYSAPI NTSTATUS ZwQuerySymbolicLinkObject(
  [in]            HANDLE          LinkHandle,
  [in, out]       PUNICODE_STRING LinkTarget,
  [out, optional] PULONG          ReturnedLength
);