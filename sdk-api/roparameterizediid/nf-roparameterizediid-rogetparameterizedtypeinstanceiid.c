HRESULT RoGetParameterizedTypeInstanceIID(
                  UINT32                     nameElementCount,
  [in]            PCWSTR                     *nameElements,
  [in]            const IRoMetaDataLocator & metaDataLocator,
  [out]           GUID                       *iid,
  [out, optional] ROPARAMIIDHANDLE           *pExtra
);