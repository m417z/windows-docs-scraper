LSA_DUPLICATE_HANDLE LsaDuplicateHandle;

NTSTATUS LsaDuplicateHandle(
  [in]  HANDLE SourceHandle,
  [out] PHANDLE DestionationHandle
)
{...}