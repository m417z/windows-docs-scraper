typedef struct value_entW {
  LPWSTR    ve_valuename;
  DWORD     ve_valuelen;
  DWORD_PTR ve_valueptr;
  DWORD     ve_type;
} VALENTW, *PVALENTW;