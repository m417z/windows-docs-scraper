EVT_WDF_DEVICE_RESOURCE_REQUIREMENTS_QUERY EvtWdfDeviceResourceRequirementsQuery;

NTSTATUS EvtWdfDeviceResourceRequirementsQuery(
  [in] WDFDEVICE Device,
  [in] WDFIORESREQLIST IoResourceRequirementsList
)
{...}