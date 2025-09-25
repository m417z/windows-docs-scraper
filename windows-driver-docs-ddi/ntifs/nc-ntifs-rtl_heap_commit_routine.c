RTL_HEAP_COMMIT_ROUTINE RtlHeapCommitRoutine;

NTSTATUS RtlHeapCommitRoutine(
  PVOID Base,
  PVOID *CommitAddress,
  PSIZE_T CommitSize
)
{...}