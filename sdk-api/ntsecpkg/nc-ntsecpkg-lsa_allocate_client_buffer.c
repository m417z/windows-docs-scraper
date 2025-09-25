LSA_ALLOCATE_CLIENT_BUFFER LsaAllocateClientBuffer;

NTSTATUS LsaAllocateClientBuffer(
  [in]  PLSA_CLIENT_REQUEST ClientRequest,
  [in]  ULONG LengthRequired,
  [out] PVOID *ClientBaseAddress
)
{...}