LSA_CLIENT_CALLBACK LsaClientCallback;

NTSTATUS LsaClientCallback(
  [in]  PCHAR Callback,
  [in]  ULONG_PTR Argument1,
  [in]  ULONG_PTR Argument2,
  [in]  PSecBuffer Input,
  [out] PSecBuffer Output
)
{...}