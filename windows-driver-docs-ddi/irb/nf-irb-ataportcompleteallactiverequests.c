VOID AtaPortCompleteAllActiveRequests(
  [in] PVOID ChannelExtension,
  [in] UCHAR Target,
  [in] UCHAR Lun,
  [in] UCHAR IrbStatus
);