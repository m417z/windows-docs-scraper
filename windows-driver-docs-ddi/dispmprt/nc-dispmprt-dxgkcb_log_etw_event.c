DXGKCB_LOG_ETW_EVENT DxgkcbLogEtwEvent;

VOID DxgkcbLogEtwEvent(
  [in] const LPCGUID EventGuid,
  [in] UCHAR Type,
  [in] USHORT EventBufferSize,
  [in] PVOID EventBuffer
)
{...}