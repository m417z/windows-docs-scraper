NTSTATUS IoPropagateActivityIdToThread(
  [in]  PIRP    Irp,
  [out] LPGUID  PropagatedId,
        LPCGUID *OriginalId
);