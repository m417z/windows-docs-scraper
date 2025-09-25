PWINBIO_LOCATE_SENSOR_CALLBACK PwinbioLocateSensorCallback;

VOID PwinbioLocateSensorCallback(
  [in, optional] PVOID LocateCallbackContext,
  [in]           HRESULT OperationStatus,
                 WINBIO_UNIT_ID UnitId
)
{...}