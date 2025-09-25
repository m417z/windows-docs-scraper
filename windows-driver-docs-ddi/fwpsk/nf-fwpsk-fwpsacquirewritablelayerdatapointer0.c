NTSTATUS FwpsAcquireWritableLayerDataPointer0(
  [in]      UINT64             classifyHandle,
  [in]      UINT64             filterId,
  [in]      UINT32             flags,
  [out]     PVOID              *writableLayerData,
  [in, out] FWPS_CLASSIFY_OUT0 *classifyOut
);