HRESULT RoGetMetaDataFile(
  [in]            const HSTRING        name,
  [in, optional]  IMetaDataDispenserEx *metaDataDispenser,
  [out, optional] HSTRING              *metaDataFilePath,
  [out, optional] IMetaDataImport2     **metaDataImport,
  [out, optional] mdTypeDef            *typeDefToken
);