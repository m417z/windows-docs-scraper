typedef struct _FILE_LINKS_INFORMATION {
  ULONG                       BytesNeeded;
  ULONG                       EntriesReturned;
  FILE_LINK_ENTRY_INFORMATION Entry;
} FILE_LINKS_INFORMATION, *PFILE_LINKS_INFORMATION;