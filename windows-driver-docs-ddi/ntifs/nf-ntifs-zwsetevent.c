NTSYSAPI NTSTATUS ZwSetEvent(
  [in]            HANDLE EventHandle,
  [out, optional] PLONG  PreviousState
);