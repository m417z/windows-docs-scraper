typedef struct RILACCESSTECHNOLOGY {
  DWORD                        cbSize;
  DWORD                        dwParams;
  DWORD                        dwSystemType;
  union {
    RILEVDOKIND    dwEvdoKind;
    RILGSMKIND     dwGsmKind;
    RILUMTSKIND    dwUmtsKind;
    RILTDSCDMAKIND dwTdscdmaKind;
    RILLTEKIND     dwLteKind;
  } RILACCESSTECHNOLOGYKINDUNION;
  RILACCESSTECHNOLOGYKINDUNION kindUnion;
} RILACCESSTECHNOLOGY, *LPRILACCESSTECHNOLOGY;