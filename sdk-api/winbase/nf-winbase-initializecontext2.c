BOOL InitializeContext2(
  [out, optional] PVOID    Buffer,
                  DWORD    ContextFlags,
  [out, optional] PCONTEXT *Context,
  [in, out]       PDWORD   ContextLength,
                  ULONG64  XStateCompactionMask
);