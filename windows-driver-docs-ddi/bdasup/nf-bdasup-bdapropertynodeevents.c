NTSTATUS BdaPropertyNodeEvents(
  [in]            PIRP      pIrp,
  [in]            PKSP_NODE pKSProperty,
  [out, optional] GUID      *pguidProperty
);