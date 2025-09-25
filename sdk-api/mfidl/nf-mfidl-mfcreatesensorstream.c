HRESULT MFCreateSensorStream(
                 DWORD           StreamId,
  [in, optional] IMFAttributes   *pAttributes,
  [in]           IMFCollection   *pMediaTypeCollection,
  [out]          IMFSensorStream **ppStream
);