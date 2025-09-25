NTSTATUS BdaPropertyNodeDescriptors(
  [in]            PIRP               pIrp,
  [in]            PKSPROPERTY        pKSProperty,
  [out, optional] BDANODE_DESCRIPTOR *pNodeDescriptorProperty
);