typedef struct _DXGKARG_GETBACKINGRESOURCE {
  ULONG                           VirtualFunctionIndex;
  USHORT                          ResourceIndex;
  PCM_PARTIAL_RESOURCE_DESCRIPTOR Resource;
  PMDL                            pMdl;
} DXGKARG_GETBACKINGRESOURCE, *PDXGKARG_GETBACKINGRESOURCE;