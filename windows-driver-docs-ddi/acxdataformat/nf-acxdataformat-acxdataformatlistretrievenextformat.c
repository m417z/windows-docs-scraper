NTSTATUS AcxDataFormatListRetrieveNextFormat(
  [in]      ACXDATAFORMATLIST             AcxDataFormatList,
  [in, out] PACX_DATAFORMAT_LIST_ITERATOR Iterator,
  [out]     ACXDATAFORMAT                 *Format
);