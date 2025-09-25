HRESULT AddTrack(
  [in]           IMAPI_CD_SECTOR_TYPE dataType,
  [in, optional] IStream              *data,
  [out, retval]  LONG                 *trackIndex
);