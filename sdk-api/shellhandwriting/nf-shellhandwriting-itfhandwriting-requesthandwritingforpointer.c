HRESULT RequestHandwritingForPointer(
  [in]  UINT32                pointerId,
  [in]  UINT64                handwritingStrokeId,
  [out] BOOL                  *requestAccepted,
  [out] ITfHandwritingRequest **request
);