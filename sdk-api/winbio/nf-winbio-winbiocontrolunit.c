HRESULT WinBioControlUnit(
  [in]            WINBIO_SESSION_HANDLE SessionHandle,
  [in]            WINBIO_UNIT_ID        UnitId,
  [in]            WINBIO_COMPONENT      Component,
  [in]            ULONG                 ControlCode,
                  PUCHAR                SendBuffer,
  [in]            SIZE_T                SendBufferSize,
                  PUCHAR                ReceiveBuffer,
  [in]            SIZE_T                ReceiveBufferSize,
                  SIZE_T                *ReceiveDataSize,
  [out, optional] ULONG                 *OperationStatus
);