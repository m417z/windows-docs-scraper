DXGKDDI_GETNODEMETADATA DxgkddiGetnodemetadata;

NTSTATUS DxgkddiGetnodemetadata(
  [in] IN_CONST_HANDLE hAdapter,
       UINT NodeOrdinalAndAdapterIndex,
       OUT_PDXGKARG_GETNODEMETADATA pGetNodeMetadata
)
{...}