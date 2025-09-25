struct IRoMetaDataLocator {
  HRESULT Locate(
    PCWSTR                     nameElement,
    IRoSimpleMetaDataBuilder & metaDataDestination
  );
};