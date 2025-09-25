PTRANSFER_CODEC_VERBS PtransferCodecVerbs;

NTSTATUS PtransferCodecVerbs(
  [in]      PVOID _context,
  [in]      ULONG Count,
  [in, out] PHDAUDIO_CODEC_TRANSFER CodecTransfer,
  [in]      PHDAUDIO_TRANSFER_COMPLETE_CALLBACK Callback,
  [in]      PVOID Context
)
{...}