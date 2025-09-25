SpInitUserModeContextFn Spinitusermodecontextfn;

NTSTATUS Spinitusermodecontextfn(
  [in] LSA_SEC_HANDLE ContextHandle,
  [in] PSecBuffer PackedContext
)
{...}