NTSTATUS WdfCompanionCreate(
  [in, out]      PWDFDEVICE_INIT        *DeviceInit,
  [in, optional] PWDF_OBJECT_ATTRIBUTES DeviceAttributes,
  [out]          WDFCOMPANION           *Companion
);