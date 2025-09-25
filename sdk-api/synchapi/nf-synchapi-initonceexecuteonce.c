BOOL InitOnceExecuteOnce(
  [in, out]           PINIT_ONCE    InitOnce,
  [in]                PINIT_ONCE_FN InitFn,
  [in, optional]      PVOID         Parameter,
  [in, out, optional] LPVOID        *Context
);