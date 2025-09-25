EVT_WDF_DEVICE_FILTER_RESOURCE_REQUIREMENTS EvtWdfDeviceFilterResourceRequirements;

NTSTATUS EvtWdfDeviceFilterResourceRequirements(
  [in] WDFDEVICE Device,
  [in] WDFIORESREQLIST IoResourceRequirementsList
)
{...}