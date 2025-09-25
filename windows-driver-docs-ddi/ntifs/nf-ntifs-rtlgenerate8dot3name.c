NTSYSAPI NTSTATUS RtlGenerate8dot3Name(
  [in]      PCUNICODE_STRING       Name,
  [in]      BOOLEAN                AllowExtendedCharacters,
  [in, out] PGENERATE_NAME_CONTEXT Context,
  [in, out] PUNICODE_STRING        Name8dot3
);