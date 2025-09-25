NTSTATUS AcxDataFormatListCreate(
  [in]  WDFDEVICE                   Device,
  [in]  PWDF_OBJECT_ATTRIBUTES      Attributes,
  [in]  PACX_DATAFORMAT_LIST_CONFIG Config,
  [out] ACXDATAFORMATLIST           *DataFormatList
);