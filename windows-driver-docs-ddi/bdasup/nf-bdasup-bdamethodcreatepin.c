NTSTATUS BdaMethodCreatePin(
  [in]            PIRP      pIrp,
  [in]            PKSMETHOD pKSMethod,
  [out, optional] PULONG    pulPinFactoryID
);