PVOID IMAGEAPI ImageRvaToVa(
  [in]           PIMAGE_NT_HEADERS     NtHeaders,
  [in]           PVOID                 Base,
  [in]           ULONG                 Rva,
  [in, optional] PIMAGE_SECTION_HEADER *LastRvaSection
);