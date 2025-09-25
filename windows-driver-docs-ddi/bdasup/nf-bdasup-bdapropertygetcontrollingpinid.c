NTSTATUS BdaPropertyGetControllingPinId(
  [in]            PIRP              Irp,
  [in]            PKSP_BDA_NODE_PIN Property,
  [out, optional] PULONG            pulControllingPinId
);