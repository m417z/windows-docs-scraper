LSA_FREE_CLIENT_BUFFER LsaFreeClientBuffer;

NTSTATUS LsaFreeClientBuffer(
  [in] PLSA_CLIENT_REQUEST ClientRequest,
  [in] PVOID ClientBaseAddress
)
{...}