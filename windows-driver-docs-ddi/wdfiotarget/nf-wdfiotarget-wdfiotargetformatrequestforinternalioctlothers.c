NTSTATUS WdfIoTargetFormatRequestForInternalIoctlOthers(
  [in]           WDFIOTARGET       IoTarget,
  [in]           WDFREQUEST        Request,
  [in]           ULONG             IoctlCode,
  [in, optional] WDFMEMORY         OtherArg1,
  [in, optional] PWDFMEMORY_OFFSET OtherArg1Offset,
  [in, optional] WDFMEMORY         OtherArg2,
  [in, optional] PWDFMEMORY_OFFSET OtherArg2Offset,
  [in, optional] WDFMEMORY         OtherArg4,
  [in, optional] PWDFMEMORY_OFFSET OtherArg4Offset
);