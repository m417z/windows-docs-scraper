VOID SpbRequestGetTransferParameters(
  [in]            SPBREQUEST              SpbRequest,
  [in]            ULONG                   Index,
  [out, optional] SPB_TRANSFER_DESCRIPTOR *TransferDescriptor,
  [out, optional] PMDL                    *TransferBuffer
);