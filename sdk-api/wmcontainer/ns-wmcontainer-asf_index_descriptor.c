typedef struct _ASF_INDEX_DESCRIPTOR {
  ASF_INDEX_IDENTIFIER Identifier;
  WORD                 cPerEntryBytes;
  WCHAR                szDescription[32];
  DWORD                dwInterval;
} ASF_INDEX_DESCRIPTOR;