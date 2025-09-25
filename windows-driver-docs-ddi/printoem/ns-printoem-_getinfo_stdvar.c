typedef struct _GETINFO_STDVAR {
  DWORD                   dwSize;
  DWORD                   dwNumOfVariable;
  struct {
    DWORD dwStdVarID;
    LONG  lStdVariable;
  };
  __unnamed_struct_0016_3 StdVar[1];
} GETINFO_STDVAR, *PGETINFO_STDVAR;