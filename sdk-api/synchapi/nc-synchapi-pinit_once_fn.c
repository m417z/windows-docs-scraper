PINIT_ONCE_FN PinitOnceFn;

BOOL PinitOnceFn(
  [in, out]           PINIT_ONCE InitOnce,
  [in, out, optional] PVOID Parameter,
  [out, optional]     PVOID *Context
)
{...}