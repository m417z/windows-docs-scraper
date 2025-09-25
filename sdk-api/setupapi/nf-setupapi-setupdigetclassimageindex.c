WINSETUPAPI BOOL SetupDiGetClassImageIndex(
  [in]  PSP_CLASSIMAGELIST_DATA ClassImageListData,
  [in]  const GUID              *ClassGuid,
  [out] PINT                    ImageIndex
);