PVOID IMAGEAPI ImageDirectoryEntryToDataEx(
  [in]            PVOID                 Base,
  [in]            BOOLEAN               MappedAsImage,
  [in]            USHORT                DirectoryEntry,
  [out]           PULONG                Size,
  [out, optional] PIMAGE_SECTION_HEADER *FoundHeader
);