NTSTATUS FwpsQueryConnectionSioFormatRedirectRecords0(
  [in]            HANDLE  RedirectRecords,
  [out, optional] PVOID   OutputBuffer,
  [in]            SIZE_T  OutputBufferLength,
  [out, optional] PSIZE_T BytesTransferred
);